#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(char * name) {
  strcpy(this->name, name);
}

Student::Student() {
  //nothing (for now)
}

Student::~Student() {
  delete name;
}
