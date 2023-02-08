#include <iostream>
#include <iomanip>
#include <cstring>
#include "student.h"

using namespace std;

//constructor
Student::Student(char * name, int id, double gpa) {
  this->name = name;
  this->id = id;
  this->gpa = gpa;
}

//default constructor
Student::Student() {
  //should never be called
}

//destructor
Student::~Student() {
  delete name;
}

void Student::getDescription() {
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
}
