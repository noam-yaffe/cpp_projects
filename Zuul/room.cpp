#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"

using namespace std;

//constructor
Room::Room(const char * name) {
  this->name = name;
}

//default constructor
Room::Room() {}

//destructor
Room::~Room() {
  delete name;
}

//description of the room: its name, the items in it, and its exit(s)
void Room::printDescription() {
  cout << endl;
  cout << "Current Room: " << name << endl;
  if (exits.size() == 0) {
    cout << endl;
    cout << "The room has no exits" << endl;
  }
  else {
    //show exits
    cout << endl;
    cout << "The room has the following exits: " << endl;
    map<const char*, Room*>::iterator it;
    for (it = exits.begin(); it != exits.end(); ++it) {
        cout << it->first << ": " << it->second->getName() << endl;
    }
    if (items.size() == 0) {
      //no items in the room
      cout << endl;
      cout << "There are no items in this room." << endl;
    }
    else {
      //show items
      cout << endl;
      cout << "Here are the items in this room:" << endl;
      vector<const char*>::iterator ptr;
      for (ptr = items.begin(); ptr < items.end(); ptr++) {
	cout << *ptr << endl;
      }
    }
  }
}

//set an individual exit that a room has
void Room::setExit(const char * exitDirection, Room* room) {
  exits.insert(pair<const char*, Room*>(exitDirection, room));
}

//get the room that corresponds with the inputted direction
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

//returns the name of the room
const char* Room::getName() {
  return name;
}

//sets the items inside the room
void Room::setItem(const char * item) {
  items.push_back(item);
}

//pick up an item from the room based off of user input
void Room::pickup(vector<const char*> &inventory) {
  int match = 0;
  cout << endl;
  if (items.size() == 0) {
    cout << "There are no items to pick up." << endl;
  }
  else {
    cout << "Enter the name of the item you want to pick up: ";
    cin.getline(itemPickup, 20);
    vector<const char*>::iterator ptr;
    for (ptr = items.begin(); ptr < items.end(); ptr++) {
      if (strcmp(itemPickup, *ptr) == 0) {
	inventory.push_back(*ptr);
	items.erase(ptr);
	cout << endl;
	cout << "Item successfully picked up!" << endl;
	match++;
	break;
      }
    }
    if (match == 0) {
      cout << endl;
      cout << "No item in the room matched the name you entered." << endl;
    }
  }
}

void Room::drop(vector<const char*> &inventory) {
  int dropped = 0;
  cout << endl;
  if (inventory.size() == 0) {
    //can't drop anything, because there's nothing there
    cout << "You do not have anything in your inventory to drop!" << endl;
  }
  else {
    cout << "Here are all the items in your inventory:" << endl;
    vector<const char*>::iterator it;
    for (it = inventory.begin(); it < inventory.end(); it++) {
      cout << *it << endl;
    }
    cout << endl;
    cout << "Enter the name of the item you want to drop: ";
    cin.getline(itemDrop, 20);
    vector<const char*>::iterator ptr;
    for (ptr = inventory.begin(); ptr < inventory.end(); ptr++) {
      if (strcmp(itemDrop, *ptr) == 0) {
        items.push_back(*ptr);
        inventory.erase(ptr);
        cout << endl;
        cout << "Item successfully dropped!" << endl;
        dropped++;
        break;
      }
    }
    if (dropped == 0) {
      cout << endl;
      cout << "No item in the room matched the name you entered." << endl;
    }
  }
}
