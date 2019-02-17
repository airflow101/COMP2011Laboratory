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
   boatposition, //boat postion (0 = right, 1 = left)
   boatcannibals, boatmissionaries /*amount of cannibals and missionaries onboard*/;

  //Initial Condition
  leftcannibals = 0; rightcannibals = 3;//Right-side
  leftmissionaries = 0; rightmissionaries = 3;//Left-side
  boatposition = 0; boatcannibals = 0; boatmissionaries = 0;//Boat

  //Game Loop
  do {
    cout << "Left side --------------------------- Right side" << '\n';
    cout << leftcannibals << "C" << leftmissionaries << "M"; //Left side condition
    if (boatposition == 1) {
      cout << ", Boat(" << boatcannibals << "C" << boatmissionaries << "M" << ")";
      for (int i = 0; i < 22; i++) {
        cout << " ";
      }
    } else {
      for (int i = 0; i < 34; i++) {
        cout << " ";
      }
    }
    cout << rightcannibals << "C" << rightmissionaries << "M"; //Right side condition
    if (boatposition == 0) {
      cout << ", Boat(" << boatcannibals << "C" << boatmissionaries << "M" << ")" << '\n';
    }
      //Loop Stopper
      leftcannibals = 3;
      leftmissionaries = 3;

  } while(leftcannibals != 3 && leftmissionaries != 3);
  //Loop and game ends as all cannibals and missionaries already at the other side

  return 0;
}
