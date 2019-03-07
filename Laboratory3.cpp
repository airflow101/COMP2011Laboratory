#include <iostream>

using namespace std;

// Check whether the given num is a three-digit number
// return true if it is, false otherwise
bool isThreeDigits(int &num) {
  if(num / 100 > 0 && num / 100 < 10){
    return true;
  }
  else{
    return false;
  }
}

// Check whether the digits of the given num are in decreasing order
// return true if it is, false otherwise
bool isDecreasingOrder(int num) {
  int hundred = num / 100;
  int dozen = (num - (hundred * 100)) / 10;
  int unit = (num - (hundred * 100)) % 10;

  if(hundred > dozen && dozen > unit){
    return true;
  }
  else {
    return false;
  }
}

// Reverse the order of the digits of the given 3-digit num
// The reversed number is returned
// For example, reverseDigit(789) returns 987
int reverseDigit(int num) {
  int reversed_unit = num / 100;
  int reversed_dozen = (num - (reversed_unit * 100)) / 10;
  int reversed_hundred = (num - (reversed_unit * 100)) % 10;

  reversed_hundred *= 100;
  reversed_dozen *= 10;

  int reversed = reversed_hundred + reversed_dozen + reversed_unit;
  return reversed;
}

// Check whether a given 3-digit decreasing order num follows 1089 magic
// return true if it is, false otherwise
// The function should also print out the calculation of 1089
// refer to the sample outputs
bool isMagic(int num) {
  int reverse_num = reverseDigit(num);
  int reverse_result = num - reverse_num;
  int magic1089 = reverse_result + reverseDigit(reverse_result);
  cout << num << ": " << num << " - " << reverse_num << " = " << reverse_result << ", ";
  cout << reverse_result << " + " << reverseDigit(reverse_result) << " = " << magic1089 << '\n';
  if (magic1089 == 1089) {
    return true;
  }
  else {
    return false;
  }
}


int main() {
	cout << "=================================================" << endl;
	cout << "Magic 1089" << endl;
	cout << "=================================================" << endl;

	cout << "Please input an arbitrary range:" << endl;
	int min, max;
	cin >> min >> max;

	while (min > max) {
		cout << "Invalid range!" << endl;
		cout << "Please input an arbitrary range:" << endl;
		cin >> min >> max;
	}

	int count_decreasing = 0;
	int count_magic = 0;

	for (int i = min; i <= max; i++)
		if (isThreeDigits(i))
			if (isDecreasingOrder(i)){
				count_decreasing++;
				if (isMagic(i))
					count_magic++;
			}

	cout << "There\'re " << count_decreasing << " 3-digit decreasing order number in the range." << endl;
	if (count_decreasing == count_magic)
		cout << "ALL follow magic 1089 rule!" << endl;
	else
		cout << "Only " << count_magic << " follow magic 1089 rule." << endl;
	return 0;
}
