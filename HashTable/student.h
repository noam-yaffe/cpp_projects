#include <iostream>
#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:
  const char * firstName = new char[20];
  const char * lastName = new char[20];
  int id;
  double gpa;
  Student(char * firstName, char * lastName, int id, double gpa);
 Student();
 ~Student();
 void getDescription();
};

#endif
