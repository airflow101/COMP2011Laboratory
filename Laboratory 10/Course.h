#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class course
{
	private:
		char name[50];
		char code[9];
		int credit;
	public:
		// Constructor member functions
		course();
		course(const char n[50], const char c[9], int cre);

		// ACCESSOR member functions
		void print_course_detail() const;
		int get_credit() const;
		void get_code(char* output) const;

		// MUTATOR member functions
		void set_credit(int cre);
};

#endif /* COURSE_H_ */
