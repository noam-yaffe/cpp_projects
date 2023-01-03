#include <iostream>
#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:
 const char * name = new char[20];
 Student(const char * name);
 Student();
 ~Student();
  const char * getName();
};

#endif
