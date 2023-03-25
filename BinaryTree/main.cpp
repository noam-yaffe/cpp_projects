#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "node.h"

using namespace std;

void fileGenerator();
void manualGenerator();
void makeTree(Node * &current, int num);
void print(Node * current, int layer);

Node * root = NULL;

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

  print(root, 0);
  
}

//generate initial binary tree via random file input
void fileGenerator() {

  cout << "File generator..." << endl;
  ifstream numbers("numbers.txt");
  srand(time(NULL));
  int num = 0;
  vector<int> nums;

  while (!numbers.eof()) {
    numbers >> num;
    nums.push_back(num);
  }

  int randomIndex = 0;
  int counter = 0;

  while (counter != 10) {
    randomIndex = (rand() % 999) + 1;
    num = nums.at(randomIndex);
    cout << num << " ";
    makeTree(root, num);
    counter++;
  }
  cout << endl;
  
}

//generate initial binary tree via by user input
void manualGenerator() {

  cout << "Manual generator..." << endl;
  //continue...
  
}

//not working atm
void makeTree(Node * &current, int num) {
  
  if (current == NULL) {
    current = new Node(num, NULL, NULL);
    return;
  }
  if (num >= current->data) {
    if (current->right == NULL) {
      current->right = new Node(num, NULL, NULL);
      return;
    }
    else {
      makeTree(current->right, num);
    }
  }
  //less than the current node
  else {
    if (current->left == NULL) {
      current->left = new Node(num, NULL, NULL);
      return;
    }
    else {
      makeTree(current->left, num);
    }
  }

}

void print(Node * current, int layer) {

  if (current == NULL) {
    return;
  }

  print(current->right, layer++);

  for (int i = 0; i < layer; i++) {
    cout << "    ";
  }
  cout << current->data << endl;

  print(current->left, layer++);
  
}
