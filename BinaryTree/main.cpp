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
void search(Node * current, int num);

Node * root = NULL;

int main() {

  char input[20];
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

  cout << endl;
  cout << "Current Tree:" << endl;
  print(root, 0);

  cout << endl;
  cout << "Here are the commands you can use:" << endl;
  cout << "Type \"SEARCH\" to search for a particular number in the tree." << endl;
  cout << "Type \"REMOVE\" to remove a particular number from the tree." << endl;
  cout << "Type \"QUIT\" to end the program." << endl;

  int numToSearch = 0;

  //commands
  do {
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 20);
    cin.get();
    //search for a number
    if (strcmp(input, "SEARCH") == 0) {
      cout << endl;
      cout << "Enter the number you want to search for: ";
      cin >> numToSearch;
      cin.get();
      search(root, numToSearch);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << "The program has ended." << endl;
    }
    else {	
      cout << "You didn't enter a valid command. Try again." << endl;
    }
  } while (strcmp(input, "QUIT") != 0);
  
}

//generate initial binary tree via random file input
void fileGenerator() {

  cout << endl;
  cout << "File generation..." << endl;
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

  print(current->right, layer + 1);

  for (int i = 0; i < layer; i++) {
    cout << "    ";
  }
  cout << current->data << endl;

  print(current->left, layer + 1);
  
}

void search(Node * current, int num) {

  int data = 0;
  
  while (current != NULL) {
    data = current->data;
    if (data == num) {
      cout << "Your number is in the tree!" << endl;
      return;
    }
    if (num > data) {
      current = current->right;
    }
    else {
      current = current->left;
    }
  }

  cout << "Your number is not in the tree." << endl;
  
}
