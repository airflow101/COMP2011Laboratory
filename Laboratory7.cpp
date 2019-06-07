#include <iostream>
#include <cstdlib>   // for srand() and rand()
#include <ctime>     // for time()
using namespace std;

void fillCubeRandomly(int [][3][3]);
void printCube(int [][3][3]);
int isMagicCube(int [][3][3]);

int main()
{
	int magicCubeSample[3][3][3] = {
			20, 16, 6,
			4, 21, 17,
			18, 5, 19,
			13, 3, 26,
			27, 14, 1,
			2, 25, 15,
			9, 23, 10,
			11, 7, 24,
			22, 12, 8};
	int cube[3][3][3] = {};

	int magicNumber = 0;

	// Generate a cube randomly and test whether it is magic cube
	cout << "Generate a cube randomly." << endl;
	fillCubeRandomly(cube);
	printCube(cube);
	magicNumber = isMagicCube(cube);
	if (magicNumber){
		cout << "It is a magic cube" << endl;
		cout << "The magic number is " << magicNumber << endl;
	}
	else {
		cout << "It is not a magic cube" << endl;
	}

	cout << endl << endl;

	// Since most likely the random generated cube is not magic cube
	// Test isMagicCube function with a magic cube sample
	cout << "Test isMagicCube function with a magic cube sample." << endl;
	printCube(magicCubeSample);
	magicNumber = isMagicCube(magicCubeSample);
	if (magicNumber){
		cout << "It is a magic cube" << endl;
		cout << "The magic number is " << magicNumber << endl;
	}
	else {
		cout << "It is not a magic cube" << endl;
	}

	return 0;
}

void fillCubeRandomly(int input_cube[][3][3]) {
	srand(time(0));
	int random_number;
	int used[] = {0, 0, 0,
		 0, 0, 0,
		 0, 0, 0,
		 0, 0, 0,
		 0, 0, 0,
		 0, 0, 0,
		 0, 0, 0,
		 0, 0, 0,
		 0, 0, 0};
		 int used_length = 0;
	for (int i = 0; i < 27; i++) {
		bool status;
		do{
			status = false;
			random_number = rand() % 27 + 1;
			for(int i = 0; i < used_length; i++){
				if(random_number == used[i]) status = true;
			}}while(status);
		used[used_length] = random_number;
		input_cube[i/9][(i/3)%3][i%3] = random_number;
		used_length++;
	}
}
void printCube(int input_cube[][3][3]) {
	for(int i = 0; i < 27; i++){
		if((i/3)%3 == 0 && i%3 == 0){
			cout << "Slice " << i/9 << endl;
		}
		cout << input_cube[i/9][(i/3)%3][i%3] << '\t';
		if(i%3 == 2){
			cout << endl;
		}
	}
}

int isMagicCube(int input_cube[][3][3]){
	int magicNumber = 0;
	int compareNumber = 0;
	for(int i = 0; i < 3; i++){
		magicNumber += input_cube[0][0][i];
	}
	//Row
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 3; j++){
			compareNumber += input_cube[i/3][i%3][j];
		}
		if(compareNumber != magicNumber) return 0;
		compareNumber = 0;
	}
	//Pilar
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 3; j++){
			compareNumber += input_cube[i/3][j][i%3];
		}
		if(compareNumber != magicNumber) return 0;
		compareNumber = 0;
	}
	//Column
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 3; j++){
			compareNumber += input_cube[j][i/3][i%3];
		}
		if(compareNumber != magicNumber) return 0;
		compareNumber = 0;
	}
	//Triagonal
	compareNumber = input_cube[1][1][1];
	compareNumber += input_cube[0][0][0] += input_cube[2][2][2];
	if (compareNumber != magicNumber) {
		return 0;
	}
	compareNumber = 0;
	compareNumber = input_cube[1][1][1];
	compareNumber += input_cube[0][0][2] += input_cube[2][2][0];
	if (compareNumber != magicNumber) {
		return 0;
	}
	compareNumber = 0;
	compareNumber = input_cube[1][1][1];
	compareNumber += input_cube[2][0][2] += input_cube[0][2][0];
	if (compareNumber != magicNumber) {
		return 0;
	}
	compareNumber = 0;
	compareNumber = input_cube[1][1][1];
	compareNumber += input_cube[2][0][0] += input_cube[0][2][2];
	if (compareNumber != magicNumber) {
		return 0;
	}
	compareNumber = 0;

return magicNumber;
}
