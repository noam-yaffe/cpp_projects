#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

//name, item(s), and exits
Room::Room(const char * name, const char * north, const char * east,
	   const char * south, const char * west) {
  this->name = name;
  northH = "NORTH";
  eastH = "EAST";
  southH = "SOUTH";
  westH = "WEST";
  exits.insert(pair<const char*, const char*>(northH, north));
  exits.insert(pair<const char*, const char*>(eastH, east));
  exits.insert(pair<const char*, const char*>(southH, south));
  exits.insert(pair<const char*, const char*>(westH, west));
}

Room::Room() {}

Room::~Room() {
  delete name;
}

//description of the room: its name, the items in it, and its exit(s)
void Room::description() {
  cout << "You are in " << name << "!" << endl;
  printExits();
}

//prints the exits of the room, called fromm the "description methods"
void Room::printExits() {
  cout << endl;
  cout << "Here are the exits available from this room:" << endl;
  map<const char*, const char*>::iterator it;
  for (it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }
}

const char* Room::getName() {
  return name;
}
