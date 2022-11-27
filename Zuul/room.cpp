#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

//name, item(s), and exits
Room::Room(const char * name) {
  this->name = name;
}

Room::Room() {}

Room::~Room() {
  delete name;
}

//description of the room: its name, the items in it, and its exit(s)
void Room::printDescription() {
  cout << endl;
  cout << "You are in " << name << endl;

  if (exits.size() == 0) {
    cout << endl;
    cout << "The room has no exits" << endl;
  }
  else {
    cout << endl;
    cout << "The room has the following exits: " << endl;
    map<const char*, Room*>::iterator it;
    for (it = exits.begin(); it != exits.end(); ++it) {
        cout << it->first << ": " << it->second->getName() << endl;
    }
  }
}

void Room::setExit(const char * exitDirection, Room* room) {
  exits.insert(pair<const char*, Room*>(exitDirection, room));
}

//prints the exits of the room, called fromm the "description methods"
Room* Room::getExit(const char * exitName) {
  map<const char*, Room*>::iterator it = exits.find(exitName);
  for (it = exits.begin(); it != exits.end(); ++it) {
    if (strcmp(exitName, it->first) == 0) {
        break;
    }
  }
  if (it == exits.end()) {
    return NULL;
  }
  else {
    return it->second;
  }
}

const char* Room::getName() {
  return name;
}
