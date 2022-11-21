#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE
#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  char * name = new char[20];
  int year;
  char * type = new char [10];
  int id;
  Media(char * name, int year);
  Media();
  ~Media();
  char * getName();
  int getYear();
  int getId();
  void print();
};

#endif
