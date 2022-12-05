#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
 char * name = new char[20];
 Student(char * name);
 Student();
 ~Student();
};
