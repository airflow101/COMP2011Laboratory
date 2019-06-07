#include "Course.h"

//Constructors
course::course(){
    strcpy(name, "N/A");
    strcpy(code, "N/A");
    credit = 0;
}

course::course(const char n[50], const char c[9], int cre){
  strcpy(name, n);
  strcpy(code, c);
  credit = cre;
}

//Accessor
void course::print_course_detail() const
{
  cout << "Course Code: " << code << " Course Name: " << name << " Credit: " << credit << endl;
}

int course::get_credit() const
{
  return credit;
}

void course::get_code(char* output) const
{
  strcpy(output, code);
}

//Mutator
void course::set_credit(int cre){
  credit = cre;
}
