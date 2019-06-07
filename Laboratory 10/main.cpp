/*
 * main.cpp
 *
 * written by Tony MOK for the course COMP2011 2019S, HKUST.
 * contact via: cwmokab@connect.ust.hk
 *
 * This piece of code is the skeleton code for Lab 10.
 * Complete the following code and finish the task specified.
 *
 */

#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;

const int COURSE_NUM = 6;
const int STUDENT_NUM = 5;

int main(){
	// Create a course array with a list of course object
    course courses[COURSE_NUM] = { { "Computer Organization", "COMP2611", 4 }, {
            "Introduction to Computer Science", "COMP1021", 3 }, {
            "Appreciation of Western Art", "HUMA1650", 3 }, {
            "Programming with C++", "COMP2011", 4 }, {
            "Operating Systems", "COMP3511", 3 }, { "Principles of Accounting I",
            "ACCT2010", 3 } };

    // Create a student array with a list of student object
    student students[STUDENT_NUM] = { {"Tony MOK", "20241500"}, {"Jierong WONG", "20515412"} };

    // Print our all the courses
    cout << "1. List all courses" << endl;
    for(int i = 0; i < COURSE_NUM; i++){
    	cout<<"- "<<i+1<<". ";
    	courses[i].print_course_detail();
    }

    cout<<endl;
    cout << "2. Register courses" << endl;
    // First student - register 3 courses
    students[0].registerCourse(courses[0]);
    students[0].registerCourse(courses[2]);
    students[0].registerCourse(courses[4]);

	// Second student - register 4 courses
    students[1].registerCourse(courses[0]);
    students[1].registerCourse(courses[1]);
    students[1].registerCourse(courses[3]);
    students[1].registerCourse(courses[5]);

    // Print out the student details and his registered courses.
    cout << "----------------" << endl;
    students[0].print_name_id();
    students[0].list_registered_courses();
    cout << "----------------" << endl;
    students[1].print_name_id();
    students[1].list_registered_courses();

    cout<<endl;
    cout << "3. Drop course" << endl;
    // Drop one course
    students[0].dropCourse(courses[2]);

    cout << "----------------" << endl;
    students[0].print_name_id();
    students[0].list_registered_courses();

    cout<<endl;
    cout << "4. Total credit earned." << endl;
    cout << "----------------" << endl;
    // Print out the earned credit for each student
    students[0].print_name_id();
    cout << students[0].get_total_credit() << " credits earned." << endl;

    cout << "----------------" << endl;
    students[1].print_name_id();
    cout << students[1].get_total_credit() << " credits earned." << endl;

    cout<<endl;
    cout << "Press enter to exit..." << endl;
    cin.get();

	return 0;
}
