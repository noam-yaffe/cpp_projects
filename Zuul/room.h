#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Room {
 public:
  char * name = new char[20];
  vector <char*> items;
  map<char*, char*> exits;
  Room(char * name, char * north, char * east, char * south, char * west);
  Room();
  ~Room();
  void description();
  void printExits();
  char* getName();
};
