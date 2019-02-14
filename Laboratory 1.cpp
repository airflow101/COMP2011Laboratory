#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]) {
  //Variable
  char answer;

  //Randomizer
  srand(time(0));
  int message = rand() % 4;

  //Print First Sentence
  cout << "Fortune Cookie" << '\n';

  //Looping
  do {
    //Print Cookie Opening Sentence
    cout << "Open a Fortune Cookie" << '\n';

    //Asking User
    cout << "Crack open another one?" << '\n';
    cin >> answer;
  } while(answer == 'y');

  return 0;
}
