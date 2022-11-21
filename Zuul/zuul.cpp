#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"

using namespace std;

int main() {
  
  vector<char*> inventory;
  char * currentRoom = new char[20];
  currentRoom = "Front Enterance";
  
  Room* FrontEnterance = new Room("Front Enterence".c_str(), "Nothing".c_str(),
				  "Nothing".c_str(), "Nothing".c_str());
  FrontEnterance->printExits();
  
  cout << endl;
  cout << "Welcome to Zuul!" << endl;
  cout << "You can type NORTH EAST SOUth or WEST when prompted to go into different rooms." << endl;
  cout << "You walked out of school when you realized that you were missing five items from your bag!" << endl;
  cout << "You must go back into the school, and, using the map, find the five items you are missing." << endl;
  cout << "Remember: You cannot leave until you find all five items!" << endl;
  cout << endl;

  
  
  return 0;
  
}
