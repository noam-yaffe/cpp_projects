#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "student.h"
#include "node.h"

using namespace std;

Student * makeStudent();
void generateTable(Node ** &table, int size);
void rehashTable(Node ** &table, int size);
bool checkCollisions(Node ** &table, int size);
void add(Node ** &table, Student * student, int index);
void printTable(Node ** table, int size);
void printChain(Node * current, Node * next, int index);
void del(Node ** &table, int idToDelete, int size);

int main() {

  char input[10];
  int idToDelete = 0;
  int num = 0;
  int size = 100;
  Node ** ht = new Node*[size];

  generateTable(ht, size);
  printTable(ht, size);

  cout << endl;
  
  cout << "Welcome to Student Hash Table! Here are the commands you can use:" << endl;
  cout << endl;
  cout << "Type \"ADD\" to add a student." << endl;
  cout << "Type \"DELETE\" to delete a student." << endl;
  cout << "Type \"PRINT\" to print out all the students." << endl;
  cout << "Type \"QUIT\" to quit." << endl;

  do {
    if (checkCollisions(ht, size)) {
      //rehash table
      cout << endl;
      cout << "Table needs to be rehashed!" << endl;
      size = size * 2;
      rehashTable(ht, size);
    }
    //getting user input for the command
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 10);
    cin.get();
    //checking what the command they entered is
    if (strcmp(input, "ADD") == 0) {
      Student * student = makeStudent();
      cout << endl;
      add(ht, student, student->id % size);
      cout << "Student has been added!" << endl;
    }
    else if (strcmp(input, "DELETE") == 0) {
	cout << "Enter the ID of the student you want to remove: ";
        cin >> idToDelete;
        cin.get();
        del(ht, idToDelete, size);
    }
    else if (strcmp(input, "PRINT") == 0) {
      printTable(ht, size);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << endl;
      cout << "This program has ended." << endl;
      delete head;
    }
    //if the user didn't enter a valid command
    else {
      cout << "You didn't enter a valid command!" << endl;
    }
  } while (strcmp(input, "QUIT") != 0);//only end the program here
  
  return 0;
  
}

Student* makeStudent() {

  char * fname = new char[20];
  char * lname = new char[20];
  int id;
  double gpa;

  cout << endl;
  cout << "Enter the student's first name: ";
  cin.getline(fname, 20);
  cout << "Enter the student's last name: ";
  cin.getline(lname, 20);
  cout << "Enter the student's ID: ";
  cin >> id;
  cout << "Enter the student's GPA: ";
  cin >> gpa;
  cin.get();
  
  Student* student  = new Student(fname, lname, id, gpa);
  return student;
  
}

//void generateNewTable(Node ** &newTable, Node ** &oldTable, int size) {}

//generates the default table which the program starts out with
void generateTable(Node ** &table, int size) {

  ifstream first_names("first_names.txt");
  ifstream last_names("last_names.txt");
  srand(time(NULL));
  int randomID = 0;
  double randomGPA = 0;
  int index = 0;
  int counter = 0;

  for (int i = 0; i < size; i++) {
    table[i] = NULL;
  }

  vector<char*> fnames;
  vector<char*> lnames;
  while (!first_names.eof() && ! last_names.eof()) {
    char * fname = new char[20];
    first_names >> fname;
    fnames.push_back(fname);
    char * lname = new char[20];
    last_names >> lname;
    lnames.push_back(lname);
  }

  int randomIndex = 0;
  
  while (counter != 20) {
    char * first = new char[20];
    char * last = new char[20];
    randomIndex = (rand() % 99) + 1;
    first = fnames.at(randomIndex);
    randomIndex = (rand() % 99) + 1;
    last = lnames.at(randomIndex);
    randomID  =((rand() % 999999) + 1);
    index = randomID % size;
    randomGPA = static_cast<double>(rand()) / RAND_MAX * 3.0 + 1;
    Student * student = new Student(first, last, randomID, randomGPA);
    Node * newNode = new Node(student);
   
    bool done = false;
    
    if (table[index] != NULL) {
      Node * current = table[index];
      while (!done) {
	if (current->next == NULL) {
	  current->next = newNode;
	  newNode->next = NULL;
	  done = true;
	}
	else {
	  current = current->next;
	}
      }
    }
    else {
      table[index] = newNode;
      newNode->next = NULL;
    }
    counter++;
  }
   
}

void rehashTable(Node ** &table, int size) {

  Node ** newTable = new Node*[size];
  int index = 0;
  
  for (int i = 0; i < size; i++) {
    if (table[i] != NULL) {
      
    }
  }

}

bool checkCollisions(Node ** &table, int size) {

  int counter = 0;
  
  for (int i = 0; i < size; i++) {
    if (table[i] != NULL) {
      Node * current = table[i];
      while (current != NULL) {
	counter++;
	current = current->next;
      }
      if (counter > 3) {
	//we need to rehash!
	return true;
      }
    }
    counter = 0;
  }

  return false;
  
}

void add(Node ** &table, Student * student, int index) {

  bool done = false;
  Node * newNode = new Node(student);
  
  if (table[index] != NULL) {
    Node * current = table[index];
    while (!done) {
      if (current->next == NULL) {
	current->next = newNode;
	newNode->next = NULL;
	done = true;
      }
      else {
	current = current->next;
      }
    }
  }
  else {
    table[index] = newNode;
    newNode->next = NULL;
  }

}

void printTable(Node ** table, int size) {

  for (int i = 0; i < size; i++) {
    if (table[i] != NULL) {
      printChain(table[i], table[i], i);
    }
    else {
      //do nothing
    }
  }
  
}

void printChain(Node * current, Node* next, int index) {
  
  if (next == current) {
    cout << endl;
    cout << "Student(s) in row " << index << ":" << endl;
  }
  if (next != NULL) {
    cout << endl;
    next->getStudent()->getDescription();
    printChain(current, next->getNext(), index);
  }
  
}

void del(Node ** &table, int idToDelete, int size) {

  int i = idToDelete % size;

  Node * current = table[i];
  Node * previous = current;
  int counter = 0;
  bool deleted = false;
  
  while (current != NULL) {
    if (current->student->id == idToDelete && counter == 0) {
      Node * headRemover = current;
      previous = current->next;
      current = current->next;
      table[i] = current;
      delete headRemover;
      deleted = true;
    }
    else if (current->student->id == idToDelete) {
      Node * temp = current;
      previous->next = current->next;
      current = current->next;
      delete temp;
      deleted = true;
    }
    else {
      previous = current;
      current = current->next;
    }
    counter++;
  }

  if (deleted) {
    cout << endl;
    cout << "Student successfully deleted!" << endl;
  }
  else {
    cout << endl;
    cout << "No student matches the entered ID" << endl;
  }
  
}
