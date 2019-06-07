/* Lab 6: Voting - An election system
 * File: lab6_skeleton.cpp
 */

#include<iostream>
using namespace std;

const int MAX_SIZE = 50;
const int MAX_STRING_LENGTH = 20;

// structure definition of Participant
struct Participant
{
   int id;
   char name[MAX_STRING_LENGTH];
   bool hasVoted; // true if voter has voted, false otherwise
   int numVotes; // number of votes received (if the participant is a candidate
};

// structure definition of Election
struct Election
{
   Participant participants[MAX_SIZE];
   int numCandidates;
   int numVoters;
   // the candidates will occupy the first numCandidates elements in the participants array,
   // while the other voters will occupy the next numVoters elements in the participants array
};

/* Print the list of candidates
 * Parameter:
 *    - election: the Election struct object
 */
void printCandidates(const Election &election)
{
   cout << "The list of candidates: " << endl;
   for (int i=0; i<election.numCandidates; i++)
       cout << "Candidate id: " << election.participants[i].id << "\tName:" << election.participants[i].name << endl;
}

/* Setup the election
 * - initialize all the member variables of the Election object
 * Parameters:
 *    - election: a Election struct object
 * Note:
 *    - id for voter/candidate has to be unique
 *    - initialize all the member variables of the Participant elements
 */
void setup(Election &election)
{
   // TODO: Complete the implementation
   //candidate Initialization
   cout << "Enter the details of the candidates: " << '\n';
   for (int i = 0; i < election.numCandidates; i++) {
     cout << "Candidate No. " << i + 1 << '\n';
     cout << '\t' << "Enter his/her id: ";
     cin >> election.participants[i].id;
     for(int j = 0; j < i;){
       if(election.participants[i].id == election.participants[j].id){
         cout << "ID already existed, please enter new ID: " << '\n';
         cin >> election.participants[i].id;
       }
       else{
         j++;
       }
     }
     cout << '\t' << "Enter Name: ";
     cin >> election.participants[i].name;
     election.participants[i].hasVoted = false;
     election.participants[i].numVotes = 0;
   }
   //Voter Initialization
   cout << "Enter the details of the voters: " << '\n';
   for (int i = election.numCandidates; i < election.numCandidates + election.numVoters; i++) {
     cout << "Voter No. " << i + 1 << '\n';
     cout << '\t' << "Enter his/her id: ";
     cin >> election.participants[i].id;
     cout << '\t' << "Enter Name: ";
     cin >> election.participants[i].name;
     election.participants[i].hasVoted = false;
     election.participants[i].numVotes = 0;
   }
}

/* Casting votes to some candidates by a specific voter given the voter id
 * Parameters:
 *    - election: the Election struct object
 *    - voterId: the voter's id
 *    - numVotes: the number of votes the voter wants to cast
 * Note:
 *    validates the following
 *    - voter id has to be existed
 *    - candidate id has to be existed
 */
void voting(Election &election, int ID, int& votesChance)
{
   // TODO: Complete the implementation
   bool voterStatus = false;
   int voteDone = 1;
   for (int i = 0; i < election.numCandidates + election.numVoters; i++) {
     /* code */
     if(election.participants[i].id == ID && election.participants[i].hasVoted == false){
       while(votesChance > 0){
         int candidateID;
         bool candidateStatus = false;
         cout << "Enter the candidate id you want to vote for: ";
         cin >> candidateID;
         for (int i = 0; i < election.numCandidates; i++) {
           if(election.participants[i].id == candidateID){
             election.participants[i].numVotes++;
             candidateStatus = true;
           }
         }
         if(candidateStatus){
           cout << "Vote " << voteDone << " done." << '\n';
           voteDone++;
           votesChance--;
         }
         else{
           cout << "No candidate with such id." << '\n';
         }
       }
       election.participants[i].hasVoted = true;
       voterStatus = true;
     }
   }
   if(!voterStatus){
     cout << "ID not eligible to vote." << '\n';
   }
}

/* Output the number of votes for each candidate
 * and announce the winner by finding who has the maximum number of votes
 * Parameters:
 *    - election: the Election struct object
 * Note: if there is more than 1 candidate has the same number of maximum votes,
 * announce it as a tie election.
 */
void resultTallying(const Election &election)
{
   // TODO: Complete the implementation
   int maximumVotes = election.participants[0].numVotes;
   int maximumID = election.participants[0].id;
   int totalVotes = 0;
   int tie = 0;
   for(int i = 0; i < election.numCandidates; i++){
     cout << "The total number of votes for candidate " << election.participants[i].id << ": ";
     cout << election.participants[i].numVotes << '\n';
     if(election.participants[i].numVotes > maximumVotes){
       maximumVotes = election.participants[i].numVotes;
       maximumID = election.participants[i].id;
     }
     totalVotes += election.participants[i].numVotes;
   }
   cout << "The total number of votes cast for the whole election: " << totalVotes<< '\n';
   for(int i = 0; i < election.numCandidates; i++){
     if(election.participants[i].numVotes == maximumVotes){
       tie++;
     }
   }
   if(tie > 1){
     cout << "Election is a tie" << '\n';
   }
   else{
     cout << "The winner is: " << maximumID << '\n';
   }
}

// Main function for the election system
int main()
{
   // Create an election
   Election election;

   cout << "===============================" << endl;
   cout << " Welcome to the voting system! " << endl;
   cout << "===============================" << endl;
   cout << "Preparing ... " << endl;
   do {
      cout << "Enter how many candidates will run for the election: \n";
      cin >> election.numCandidates;
      cout << "Enter how many more voters: \n";
      cin >> election.numVoters;
   } while (((election.numCandidates + election.numVoters) > MAX_SIZE) || (election.numCandidates <= 0));
   cout << "\n";

   // the setup phase
   setup(election);

   int currentId;
   int numVotes = 0;
   // the voting phase
   cout << "Voting starts ..." << endl;
   printCandidates(election);

   char cmd;
   //for (int i = 0; i < (election.numCandidates + election.numVoters); i++)
   do {
      cout << "Enter the voter id to start voting:\n";
      cin >> currentId;

      do {
         cout << "Enter the number of votes to be cast (<" << election.numCandidates+1 << ") :\n";
         cin >> numVotes;
      } while (numVotes > election.numCandidates);

      voting(election, currentId, numVotes);

      cout << "Continue with the next voter? (y/n) ";
      cin >> cmd;
   } while ((cmd == 'y') || (cmd == 'Y'));

   cout << "Tallying votes ..." << endl;
   //the result-tallying phase
   resultTallying(election);

   cout << "End of the election!" << endl;
   return 0;
}
