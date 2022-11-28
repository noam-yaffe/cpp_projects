#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Room {
 public:
  const char * name = new char[20];
  vector<const char*> items;
  map<const char*, Room*> exits;
  char * itemPickup = new char[20];
  char * itemDrop = new char[20];
  Room(const char * name);
  Room();
  ~Room();
  void printDescription();
  void setExit(const char * exitDirection, Room* room);
  Room* getExit(const char * exitName);
  const char* getName();
  void setItem(const char * item);
  const char* getItems();
  void pickup(vector<const char*> &inventory);
  void drop(vector<const char*> &inventory);
};
