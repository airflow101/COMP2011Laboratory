#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]) {
  srand(time(0));
  int message = rand() % 4;
  cout << "Fortune Cookie" << '\n';
  return 0;
}
