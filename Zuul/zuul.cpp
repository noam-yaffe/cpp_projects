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

  //all items
  mainOffice->setItem("Student ID");
  scienceClass->setItem("Notebook");
  computerLab->setItem("Chromebook");
  mathClass->setItem("Homework");
  gym->setItem("Water Bottle");

  //introducing Zuul
  cout << endl;
  cout << "Welcome to Zuul!" << endl;
  cout << endl;
  cout << "When prompted to enter an action, here are your options:" << endl;
  cout << "You can type NORTH EAST SOUTH or WEST to go into different rooms." << endl;
  cout << "There are five objects around the map that you need to collect. Enter PICKUP and when prompted enter the" << endl;
  cout << "name of the object to pick it up and store it in your inventory." << endl;
  cout << "Enter DROP and when prompted enter the name of the object to drop it in the current room." << endl;
  cout << "You can also enter QUIT when prompted with an action to end the game early." << endl;
  cout << endl;
  cout << "Here is the scenario:" << endl;
  cout << endl;
  cout << "You walked out of school when you realized that you were missing five items from your bag!" << endl;
  cout << "You must go back into the school and, using the map, find the five items you are missing." << endl;
  cout << "Objective: Collect all five items, and go back to the Front Entrance to leave." << endl;
  cout << "Remember: You have to have all five items IN YOUR INVENTORY to leave!" << endl;

  //start at the front entrance
  Room* currentRoom = frontEntrance;
  char * action = new char[10];
  vector<const char*> inventory;

  while (true) {
    if (currentRoom == frontEntrance && inventory.size() == 5) {
      cout << endl;
      cout << "You win! You got all five items, and you may now leave the school." << endl;
      break;
    }
    currentRoom->printDescription();
    cout << endl;
    cout << "Enter a direction or action: ";
    cin.getline(action, 10);
    if (strcmp(action, "PICKUP") == 0) {
      //pick up the item in the current room, if there is one
      currentRoom->pickup(inventory);
    }
    else if (strcmp(action, "DROP") == 0) {
      //drop an item from the inventory into the current room, if there is one
      currentRoom->drop(inventory);
    }
    else if (strcmp(action, "QUIT") == 0) {
      //end the game early
      break;
    }
    else {
      //action was a directiional one, or a misinput
      Room* nextRoom = currentRoom->getExit(action);
      if (nextRoom != NULL) {
	currentRoom = nextRoom;
      }
      else {
	cout << endl;
	cout << "Invalid input." << endl;
      }
    }
  }

  cout << endl;
  cout << "Thanks for playing!" << endl;  

  return 0;
  
}
