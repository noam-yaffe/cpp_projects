#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"

using namespace std;

int main() {

  //names of rooms
  const char * nothing = "Nothing";
  const char * front = "Front Enterance";
  const char * m1 = "Main Hall 1";
  
  vector<char*> inventory;
  
  Room* FrontEnterance = new Room(front, m1, nothing, nothing, nothing);
  
  cout << endl;
  cout << "Welcome to Zuul!" << endl;
  cout << "You can type NORTH EAST SOUth or WEST when prompted to go into different rooms." << endl;
  cout << "You walked out of school when you realized that you were missing five items from your bag!" << endl;
  cout << "You must go back into the school, and, using the map, find the five items you are missing." << endl;
  cout << "Remember: You cannot leave until you find all five items!" << endl;
  cout << endl;

  cout << "You are currently at the " << front << endl;
  FrontEnterance->printExits();
  
  return 0;
  
}
