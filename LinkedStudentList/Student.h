#include <iostream>
#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:
  const char * name = new char[20];
  int id;
  double gpa;
  Student(char * name, int id, double gpa);
 Student();
 ~Student();
 void getDescription();
};

#endif
