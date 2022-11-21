#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {
 public:
  char * director = new char[20];
  int duration;
  int rating;
  Movie(char * name, int year, char * director, int duration,
            int rating, int id);
  ~Movie();
  void print();
};
