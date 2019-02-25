#include <iostream>

using namespace std;

// Check whether the given num is a three-digit number
// return true if it is, false otherwise
bool isThreeDigits(int num) {


}

// Check whether the digits of the given num are in decreasing order
// return true if it is, false otherwise
bool isDecreasingOrder(int num) {


}

// Reverse the order of the digits of the given 3-digit num
// The reversed number is returned
// For example, reverseDigit(789) returns 987
int reverseDigit(int num) {


}

// Check whether a given 3-digit decreasing order num follows 1089 magic
// return true if it is, false otherwise
// The function should also print out the calculation of 1089
// refer to the sample outputs
bool isMagic(int num) {


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
