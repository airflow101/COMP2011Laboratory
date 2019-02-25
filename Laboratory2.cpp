//Missionaries & Cannibals
//by Bryan Suryaraso Gani
//COMP2011 Laboratory ASsignment 2

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Game Start!" << '\n';//Start The Game

  //Variables declaration
  int leftcannibals, rightcannibals, //amount of cannibals per side
   leftmissionaries, rightmissionaries, //amount of missionaries per side
   boatstatus, //boat postion (0 =  boarding from right, 1 = landing  at left, 2 = boarding from left, 3 = landing at right)
   boatcannibals, boatmissionaries, //amount of cannibals and missionaries onboard
   promptcannibals, promptmissionaries; //amount of cannibals and missionaries inputed
  char confirmationQA;//confirming player input

  //Initial Condition
  leftcannibals = 0; rightcannibals = 3;//Right-side
  leftmissionaries = 0; rightmissionaries = 3;//Left-side
  boatcannibals = 0; boatmissionaries = 0;//Boat

  //Game Loop
  for (boatstatus = 0; ; boatstatus++) {
    if (boatstatus % 4 == 1){
      if ((rightcannibals > rightmissionaries && rightmissionaries > 0) || ((boatcannibals + leftcannibals) > (boatmissionaries + leftmissionaries) && (boatmissionaries + leftmissionaries > 0))) {
        cout << "Cannibals eat a missionaries. You FAILED!" << '\n';
        break;
      }
    }
    else if (boatstatus % 4 == 3){
      if ((leftcannibals > leftmissionaries && leftmissionaries > 0) || ((boatcannibals + rightcannibals) > (boatmissionaries + rightmissionaries) && (boatmissionaries + rightmissionaries > 0))) {
        cout << "Cannibals eat a missionaries. You FAILED!" << '\n';
        break;
      }
    }
    else if (leftcannibals == 3 && leftmissionaries == 3) {
      cout << "Congratulations! You manage to move everyone to the destination!" << '\n';
      break;
    }



    //Condition at Location
    cout << "Left side --------------------------- Right side" << '\n';
    cout << leftcannibals << "C" << leftmissionaries << "M"; //Left side condition
    if (boatstatus % 4 == 1 || boatstatus % 4 == 2) {
      cout << ", Boat(" << boatcannibals << "C" << boatmissionaries << "M)";
      for (int i = 0; i < 22; i++) {
        cout << " ";
      }
    } else {
      for (int i = 0; i < 34; i++) {
        cout << " ";
      }
    }
    cout << rightcannibals << "C" << rightmissionaries << "M"; //Right side condition
    if (boatstatus % 4 == 0 || boatstatus % 4 == 3) {
      cout << ", Boat(" << boatcannibals << "C" << boatmissionaries << "M)" << '\n';
    }
    else{
      cout << '\n';
    }

    //Prompt - Getting ON/OFF The Boat
    string boatcondition;
    if (boatstatus % 4 == 0 || boatstatus % 4 == 2) {
      boatcondition = "ON";
    } else {
      boatcondition  = "OFF";
    }
    do {
      cout << "How many missionaries get " << boatcondition  << " the boat?" << '\n';
      cin >> promptmissionaries;//Misionaries
      cout << "How many cannibals get " << boatcondition << " the boat?" << '\n';
      cin >> promptcannibals;//Cannibals

      //Getting on / off the boat
      if (boatstatus % 4 == 0 || boatstatus % 4 == 2) {
        cout << "Ready to go? (Y/N)" << '\n';
        cin >> confirmationQA;
        cout << endl;
      } else {
        cout << "Ready to get off? (Y/N)" << '\n';
        cin >> confirmationQA;
        cout << endl;

      }
    } while(confirmationQA == 'n' || confirmationQA == 'N');

    //Calculating people moved;
    if(boatstatus % 4 == 0){
      //Assign to boat
      boatmissionaries += promptmissionaries;
      boatcannibals += promptcannibals;
      //Subtract from field
      rightcannibals -= promptcannibals;
      rightmissionaries -= promptmissionaries;
    }
    else if(boatstatus % 4 == 2){
      //Assign to boat
      boatmissionaries += promptmissionaries;
      boatcannibals += promptcannibals;
      //Subtract from field
      leftcannibals -= promptcannibals;
      leftmissionaries -= promptmissionaries;
    }
    else if(boatstatus % 4 == 1){
      //Take from boat
      boatmissionaries -= promptmissionaries;
      boatcannibals -= promptcannibals;
      //Add to field
      leftcannibals += promptcannibals;
      leftmissionaries += promptmissionaries;
    }
    else{
      //Take from boat
      boatmissionaries -= promptmissionaries;
      boatcannibals -= promptcannibals;
      //Add to field
      rightcannibals += promptcannibals;
      rightmissionaries += promptmissionaries;
    }
  }
  //Loop and game ends as all cannibals and missionaries already at the other side

  return 0;
}
