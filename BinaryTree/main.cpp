#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

void fileGenerator();
void manualGenerator();

int main() {

  int answer = 0;
  bool cont = false;
  cout << endl;
  cout << "Welcome to Binary Search Tree!" << endl;

  do {
    cout << endl;
    cout << "Type 1 to generate the numbers with a file (automatically generates 50 random numbers), type 2 to generate them manually\
: ";
    cin >> answer;
    cin.get();
    //generate through file input
    if (answer == 1) {
      fileGenerator();
      cont = true;
    }
    //generate through user input
    else if (answer == 2) {
      manualGenerator();
      cont = true;
    }
    //invalid input
    else {
      cout << endl;
      cout << "You didn't enter a valid choice! Try again." << endl;
    }
  } while(!cont);
  
}

//generate initial binary tree via random file input
void fileGenerator() {

  cout << "File generator..." << endl;
  //continue;
  
}

//generate initial binary tree via by user input
void manualGenerator() {

  cout << "Manual generator..." << endl;
  //continue...
  
}
