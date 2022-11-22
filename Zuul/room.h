#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Room {
 public:
  const char * name = new char[20];
  const char * northH = new char[10];
  const char * eastH = new char[10];
  const char * southH = new char[10];
  const char * westH = new char[10];
  vector <char*> items;
  map<const char*, const char*> exits;
  Room(const char * name, const char * north, const char * east,
           const char * south, const char * west);
  Room();
  ~Room();
  void description();
  void printExits();
  const char* getName();
};
