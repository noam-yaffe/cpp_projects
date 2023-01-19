#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

Node * head = NULL;

Student* makeStudent();
void add(Node * c, Node * p, Node * &head, Student * student);
void print(Node* next);

int main() {

  char input[10];

  cout << "Welcome to Student Linked List! Here are the commands you can use:" << endl;
  cout << endl;
  cout << "Type \"ADD\" to add a student." << endl;
  cout << "Type \"DELETE\" to delete a student." << endl;
  cout << "Type \"PRINT\" to print out all the students." << endl;
  cout << "Type \"QUIT\" to quit." << endl;

  do {
    //getting user input for the command
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 10);
    cin.get();
    //checking what the command they entered is
    if (strcmp(input, "ADD") == 0) {
      Student * student = makeStudent();
      cout << endl;
      add(head, head, head, student);
      cout << "Student has been added!" << endl;
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter the ID of the student you want to remove: ";
      //cin >> idToDelete;
      cin.get();
      //del(students, idToDelete);
    }
    else if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << endl;
      cout << "This program has ended." << endl;
    }
    //if the user didn't enter a valid command
    else {
      cout << "You didn't enter a valid command!" << endl;
    }
  } while (strcmp(input, "QUIT") != 0);//only end the program here
  
  return 0;
  
}

Student* makeStudent() {

  char * name = new char[20];
  int id;
  double gpa;

  cout << endl;
  cout << "Enter the name of the student (first and last): ";
  cin.getline(name, 20);
  cout << "Enter the student's ID: ";
  cin >> id;
  cout << "Enter the student's GPA: ";
  cin >> gpa;
  cin.get();
  
  Student* student  = new Student(name, id, gpa);
  return student;
  
}

void add(Node * c, Node * p, Node * &head, Student * student) {

  if (head == NULL) {
    head = new Node(student);
    return;
  }
  else if (student->id < head->getStudent()->id) {
    Node * newN = new Node(student);
    newN->setNext(head);
    head = newN;
    return;
  }
  else if (student->id < c->getStudent()->id) {
    Node * newN = new Node(student);
    p->setNext(newN);
    newN->setNext(c);
    return;
  }
  if (c->getNext() == NULL) {
    Node * newN = new Node(student);
    c->setNext(newN);
    newN->setNext(NULL);
    return;
  }
  add(c->getNext(), c, head, student);
  
}

void print(Node* next) {
  
  if (next == head) {
    cout << endl;
    cout << "Students currently in the list:" << endl;
  }
  if (next != NULL) {
    cout << endl;
    next->getStudent()->getDescription();
    print(next->getNext());
  }
  
}
