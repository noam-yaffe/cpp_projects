#include <iostream>
#include "Student.h"

using namespace std;

//constructor
Student::Student(const char * name) {
  this->name = name;
}

//default constructor
Student::Student() {
  //should never be called
}

//destructor
Student::~Student() {
  delete name;
}

const char * Student::getName() {
  return name;
}
