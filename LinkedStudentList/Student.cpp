#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

//constructor
Student::Student(char name[20], int id, float gpa) {
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
  cout << setprecision(3) << "GPA: " << gpa << endl;
}
