#include <iostream>
#include <iomanip>
#include <cstring>
#include "student.h"

using namespace std;

//constructor
Student::Student(char * firstName, char * lastName, int id, double gpa) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->id = id;
  this->gpa = gpa;
}

//default constructor
Student::Student() {
  //should never be called
}

//destructor
Student::~Student() {
  delete firstName;
  delete lastName;
}

void Student::getDescription() {
  cout << "Name: " << firstName << " " << lastName << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
}
