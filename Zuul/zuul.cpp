#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"

using namespace std;

int main() {

  //all of the rooms
  Room* frontEntrance = new Room("Front Entrance");
  Room* mainHall1 = new Room("Main Hall 1");
  Room* mainOffice = new Room("Main Office");
  Room* businessClass = new Room("Business Class");
  Room* spanishClass = new Room("Spanish Class");
  Room* roboticsClass = new Room("Robotics Class");
  Room* historyClass = new Room("History Class");
  Room* mainHall2 = new Room("Main Hall 2");
  Room* gym = new Room("Gym");
  Room* englishClass = new Room("English Class");
  Room* mathClass = new Room("Math Class");
  Room* theater = new Room("Theater");
  Room* scienceClass = new Room("Science Class");
  Room* artClass = new Room("Art Class");
  Room* computerLab = new Room("Computer Lab");

  //all possible exits
  frontEntrance->setExit("NORTH", mainHall1);
  mainHall1->setExit("NORTH", mainOffice);
  mainHall1->setExit("EAST", businessClass);
  mainHall1->setExit("SOUTH", frontEntrance);
  mainHall1->setExit("WEST", spanishClass);
  spanishClass->setExit("EAST", mainHall1);
  spanishClass->setExit("WEST", roboticsClass);
  mainOffice->setExit("NORTH", mainHall2);
  mainOffice->setExit("SOUTH", mainHall1);
  businessClass->setExit("EAST", historyClass);
  businessClass->setExit("WEST", mainHall1);
  mainHall2->setExit("NORTH", gym);
  mainHall2->setExit("EAST", theater);
  mainHall2->setExit("SOUTH", mainOffice);
  mainHall2->setExit("WEST", scienceClass);
  gym->setExit("SOUTH", mainHall2);
  historyClass->setExit("NORTH", englishClass);
  historyClass->setExit("WEST", businessClass);
  englishClass->setExit("NORTH", mathClass);
  englishClass->setExit("SOUTH", historyClass);
  mathClass->setExit("SOUTH", englishClass);
  mathClass->setExit("WEST", theater);
  theater->setExit("EAST", mathClass);
  theater->setExit("WEST", mainHall2);
  scienceClass->setExit("EAST", mainHall2);
  scienceClass->setExit("WEST", artClass);
  artClass->setExit("EAST", scienceClass);
  artClass->setExit("SOUTH", computerLab);
  computerLab->setExit("NORTH", artClass);
  computerLab->setExit("SOUTH", roboticsClass);
  roboticsClass->setExit("NORTH", computerLab);
  roboticsClass->setExit("EAST", spanishClass);
  
  cout << endl;
  cout << "Welcome to Zuul!" << endl;
  cout << "You can type NORTH EAST SOUth or WEST when prompted to go into different rooms." << endl;
  cout << "You walked out of school when you realized that you were missing five items from your bag!" << endl;
  cout << "You must go back into the school, and, using the map, find the five items you are missing." << endl;
  cout << "Remember: You cannot leave until you find all five items!" << endl;

  //start at the front entrance
  Room* currentRoom = frontEntrance;
  char * direction = new char[10];

  while (true) {
    currentRoom->printDescription();
    cout << endl;
    cout << "Enter the direction you want to go to: ";
    cin.getline(direction, 10);
    Room* nextRoom = currentRoom->getExit(direction);
    if (nextRoom != NULL) {
      currentRoom = nextRoom;
    }
    else {
      cout << "You cannot go there!" << endl;
    }
  }
  
  return 0;
  
}
