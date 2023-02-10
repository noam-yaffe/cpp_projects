#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "student.h"
#include "node.h"

using namespace std;

Node * head = NULL;

Student* makeStudent();
void add(Node * c, Node * p, Node * &head, Student * student);
void print(Node* next);
void del(Node * &head, int idToDelete);

int main() {

  char input[10];
  int idToDelete = 0;
  int num = 0;
  int size = 100;

  Node ** ht = new Node*[size];

  //random id generator code
  srand((unsigned) time(NULL));
  int randomID = ((rand() % 999999) + 1) % size;
  
  cout << randomID << endl;
  
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
      if (head == NULL) {
	cout << "nothing to delete" << endl;
      }
      else {
	cout << "Enter the ID of the student you want to remove: ";
        cin >> idToDelete;
        cin.get();
        del(head, idToDelete);
      }
    }
    else if (strcmp(input, "PRINT") == 0) {
      if (head == NULL) {
	cout << endl;
	cout << "There are no students currently in the list." << endl;
      }
      else {
	print(head);
      }
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

  char * first = new char[20];
  char * last = new char[20];
  int id;
  double gpa;

  cout << endl;
  cout << "Enter the student's first name: ";
  cin.getline(first, 20);
  cout << "Enter the student's last name: ";
  cin.getline(last, 20);
  cout << "Enter the student's ID: ";
  cin >> id;
  cout << "Enter the student's GPA: ";
  cin >> gpa;
  cin.get();
  
  Student* student  = new Student(first, last, id, gpa);
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

void del(Node * &head, int idToDelete) {

  Node * current = head;
  Node * previous = current;
  int counter = 0;
  
  while (current != NULL) {
    if (current->student->id == idToDelete && counter == 0) {
      Node * headRemover = current;
      previous = current->next;
      current = current->next;
      head = current;
      delete headRemover;
    }
    else if (current->student->id == idToDelete) {
      Node * temp = current;
      previous->next = current->next;
      current = current->next;
      delete temp;
    }
    else {
      previous = current;
      current = current->next;
    }
    counter++;
  }

  cout << endl;
  cout << "Student successfully deleted!" << endl;
  
}
