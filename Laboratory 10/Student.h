#ifndef STUDENT_H_
#define STUDENT_H_

#include "Course.h"

// Constant Definition

const int MAX_COURSES = 5;

// Class Definition
class student
{
	private:
		char name[20];
		char id[9];
		int num_registered_course;
		course courses[MAX_COURSES];

	public:
		// CONSTRUCTOR member function
		student();
		student(const char n[20], const char i[9]);

		// ACCESSOR member functions
		void list_registered_courses() const;
		void print_name_id() const;
		int get_total_credit() const;

		// MUTATOR member functions
		bool registerCourse(const course &c);
		bool dropCourse(const course &c);
};


#endif /* STUDENT_H_ */
