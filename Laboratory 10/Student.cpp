#include "Student.h"

//Constructor
student::student(){
  strcpy(name, "N/A");
  strcpy(id, "N/A");
  num_registered_course = 0;
}

student::student(const char n[20], const char i[9]){
  strcpy(name, n);
  strcpy(id, i);
  num_registered_course = 0;
}

//Acessor
void student::list_registered_courses() const
{
  for(int i = 0; i < num_registered_course; i++){
    courses[i].print_course_detail();
  }
}

void student::print_name_id() const
{
  cout << "Name: " << name << " ID: " << id << endl;
}

int student::get_total_credit() const
{
  int credit = 0;
  for(int i = 0; i < num_registered_course ; i++){
    credit += courses[i].get_credit();
  }
  return credit;
}

//Mutator
bool student::registerCourse(const course &c)
{
  if(num_registered_course >= MAX_COURSES) return false;
  courses[num_registered_course] = c;
  num_registered_course++;
  return true;
}
bool student::dropCourse(const course &c)
{
  char *compared_course = new char[9];
  char *checked_courses = new char[9];
  c.get_code(compared_course);

  for(int i = 0; i < num_registered_course; i++)
  {
    courses[i].get_code(checked_courses);
    if(!(strcmp(checked_courses, compared_course))){
      cout << "Student " << name << "(" << id << ") dropped course " << compared_course << "." << endl;
      num_registered_course--;
      for(int j = i; j < num_registered_course; j++){
        courses[j] = courses[j+1];
      }
      delete compared_course;
      delete checked_courses;
      return true;
    }
  }
  return false;
}
