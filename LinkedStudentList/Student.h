#include <iostream>
#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:
  const char * name = new char[20];
  int id;
  float gpa;
  Student(char name[20], int id, float gpa);
 Student();
 ~Student();
 void getDescription();
};

#endif
