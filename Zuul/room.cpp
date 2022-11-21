#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

//name, item(s), and exits
Room::Room(char * name, char * north, char * east, char * south, char * west) {
  strcpy(this->name, name);
  exits.insert(pair<char*, char*>("NORTH".c_str(), north));
  exits.insert(pair<char*, char*>("EAST".c_str(), east));
  exits.insert(pair<char*, char*>("SOUTH".c_str(), south));
  exits.insert(pair<char*, char*>("WEST".c_str(), west));
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
  map<char*, char*>::iterator it;
  for (it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << ": " << it->second;
  }
}

char* Room::getName() {
  return name;
}
