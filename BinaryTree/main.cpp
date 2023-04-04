#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "node.h"

using namespace std;

void fileGenerator();
void manualGenerator();
void insert(Node * &current, int num);
void print(Node * current, int layer);
void search(Node * current, int num);
Node * remove(Node * current, int num);

Node * root = NULL;

int main() {

  char input[20];
  int answer = 0;
  bool cont = false;

  cout << endl;
  cout << "Welcome to Binary Search Tree!" << endl;

  do {
    cout << endl;
    cout << "Type 1 to generate the numbers with a file (automatically generates 10 random numbers), type 2 to generate them manually\
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
  print(root, 0);

  cout << endl;
  cout << "Here are the commands you can use:" << endl;
  cout << "Type \"ADD\" to add a number to the tree;" << endl;
  cout << "Type \"SEARCH\" to search for a particular number in the tree." << endl;
  cout << "Type \"REMOVE\" to remove a particular number from the tree." << endl;
  cout << "Type \"PRINT\" to print out the tree." << endl;
  cout << "Type \"QUIT\" to end the program." << endl;

  int actionNumber = 0;

  //commands
  do {
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 20);
    cin.get();
    //add a number
    if (strcmp(input, "ADD") == 0) {
      cout << endl;
      cout << "Enter the number you want to add: ";
      cin >> actionNumber;
      cin.get();
      insert(root, actionNumber);
      cout << "Number has been added!" << endl;
    }
    //search for a number
    else if (strcmp(input, "SEARCH") == 0) {
      cout << endl;
      cout << "Enter the number you want to search for: ";
      cin >> actionNumber;
      cin.get();
      search(root, actionNumber);
    }
    //remove a number
    else if(strcmp(input, "REMOVE") == 0) {
      cout << endl;
      cout << "Enter the number you want to remove: ";
      cin >> actionNumber;
      cin.get();
      root = remove(root, actionNumber);
      cout << "Number has been removed!" << endl;
    }
    //print out the tree
    else if (strcmp(input, "PRINT") == 0) {
      cout << endl;
      print(root, 0);
    }
    //end the program
    else if (strcmp(input, "QUIT") == 0) {
      cout << endl;
      cout << "The program has ended." << endl;
    }
    else {	
      cout << "You didn't enter a valid command. Try again." << endl;
    }
  } while (strcmp(input, "QUIT") != 0);
  
}

//generate initial binary tree via random file input
void fileGenerator() {

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
    insert(root, num);
    counter++;
  }
  cout << endl;
  
}

//generate initial binary tree via by user input
void manualGenerator() {

  int input = 0;
  int counter = 0;

  cout << endl;
  cout << "You will be prompted to manually enter numbers one-by-one." << endl;
  cout << "You can terminate the loop by entering the number -1, but it automatically ends after you've entered a total of 50 numbers\
." << endl;

  while (input != 0 || counter < 50) {
    cout << endl;
    cout << "Enter a number: ";
    cin >> input;
    if (input == -1) {
      break;
    }
    else {
      insert(root, input);
      cout << endl;
      cout << "Number has been entered into the tree!" << endl;
      counter++;
    }
  }

  cin.get();
  
}

//add data into the tree
void insert(Node * &current, int num) {
  
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
      insert(current->right, num);
    }
  }
  //less than the current node
  else {
    if (current->left == NULL) {
      current->left = new Node(num, NULL, NULL);
      return;
    }
    else {
      insert(current->left, num);
    }
  }

}

//print out the tree (using the inOrder traversal algorithm)
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

//The algorithm below was inspired by the GeeksForGeeks article linked below:
//https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
Node * remove(Node * current, int num) {

  if (current == NULL) {
    return current;
  }

  //searching for the node recursively
  if (num > current->data) {
    current->right = remove(current->right, num);
    return current;
  }
  if (num < current->data) {
    current->left = remove(current->left, num);
    return current;
  }
  //node has been found
  else {
    //no children
    if (current->right == NULL && current->left == NULL) {
      return NULL;
    }
    //one right child
    else if (current->left == NULL) {
      Node * temp = current->right;
      delete current;
      return temp;
    }
    //one left child
    else if (current->right == NULL) {
      Node * temp = current->left;
      delete current;
      return temp;
    }
    //two children
    else {
      Node * succParent = current;
      Node * succ = current->left;
      //find node to replace current with
      while (succ->right != NULL) {
	succParent = succ;
	succ = succ->right;
      }
      if (succParent != current) {
	succParent->right = succ->left;
      }
      //current's left is the replacement
      else {
	succParent->left = succ->left;
      }
      current->data = succ->data;
      delete succ;
      return current;
    }
  }

  return current;
 
}
