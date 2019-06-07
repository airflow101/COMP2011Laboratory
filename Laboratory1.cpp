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
    int message = rand() % 6 + 1;

    //Print Cookie Opening Sentence
    cout << "Open a Fortune Cookie" << '\n';

    //Message
    if (message == 1) {
      cout << "\"You cannot love life until you live the life you love.\"" << '\n';
    } else if (message == 2) {
      cout << "\"Put your unhappiness aside. Life is beautiful, be happy.\"" << '\n';
    } else if (message == 3){
      cout << "\"If you speak honestly, everyone will listen.\"" << '\n';
    } else if (message == 4){
      cout << "\"Make a wise choice everyday.\"" << '\n';
    } else if (message == 5){
      cout << "\"Good things take time.\"" << '\n';
    } else {
      cout << "\"You create your own stage ... the audience is waiting.\"" << '\n';
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
