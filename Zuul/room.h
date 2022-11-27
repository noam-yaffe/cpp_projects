#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Room {
 public:
  const char * name = new char[20];
  vector <char*> items;
  map<const char*, Room*> exits;
  Room(const char * name);
  Room();
  ~Room();
  void printDescription();
  void setExit(const char * exitDirection, Room* room);
  Room* getExit(const char * exitName);
  const char* getName();
};
