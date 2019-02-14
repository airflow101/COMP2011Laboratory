#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]) {
  //Variable
  char answer;

  //Print First Sentence
  cout << "Fortune Cookie" << '\n';

  //Looping
  do {
    //Randomizer
    srand(time(0));
    int message = rand() % 4 + 1;

    //Print Cookie Opening Sentence
    cout << "Open a Fortune Cookie" << '\n';
    cout << message << '\n';

    //Message
    if (message == 0) {
      cout << "You cannot love life until you live the life you love." << '\n';
    } else if (message == 1) {
      cout << "Put your unhappiness aside. Life is beautiful, be happy." << '\n';
    } else {
      cout << "Make a wise choice everyday." << '\n';
    }

    //Asking User
    cout << "Crack open another one?" << '\n';
    cin >> answer;
    cout << endl;
  } while(answer == 'y');

  //Closing Program
  cout << "Bye!" << '\n';
  return 0;
}
