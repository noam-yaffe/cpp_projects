#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {
 public:
  char * publisher = new char[20];
  int duration;
  char * artist = new char[20];
  Music(char * name, int year, char * publisher, int duration,
	    char * artist, int id);
  ~Music();
  void print();
};
