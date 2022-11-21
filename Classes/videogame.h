#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Videogame : public Media {
 public:
  char * publisher = new char[20];
  int rating;
  Videogame(char * name, int year, char * publisher, int rating, int id);
  ~Videogame();
  void print();
};
