#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "node.h"

using namespace std;

Node * head = NULL;

Student* makeStudent();
void add(Node * c, Node * p, Node * &head, Student * student);
void print(Node* next);
void del(Node * &head, int idToDelete);
int getCount(Node * head);
void average(Node * next, int number, double avg);

int main() {

  char input[10];
  int idToDelete = 0;
  int num = 0;
  
  cout << "Welcome to Student Linked List! Here are the commands you can use:" << endl;
  cout << endl;
  cout << "Type \"ADD\" to add a student." << endl;
  cout << "Type \"DELETE\" to delete a student." << endl;
  cout << "Type \"PRINT\" to print out all the students." << endl;
  cout << "Type \"AVERAGE\" to average out all GPA's of the students' GPAs." << endl;
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
    else if (strcmp(input, "AVERAGE") == 0) {
      if (head == NULL) {
	cout << endl;
	cout << "There are no students currently in the list." << endl;
      }
      else {
	num = getCount(head);
	average(head, num, 0);
      }
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

int getCount(Node * head) {

  int counter = 0;
  Node * current = head;
  
  while (current != NULL) {
    counter++;
    if (current->next == NULL) {
      return counter;
    }
    current = current->next;
  }

  return 0;
  
}

void average(Node * next, int number, double avg) {
  
  if (next == head) {
    //do nothing
  }
  if (next != NULL) {
    avg += next->student->gpa;
    average(next->getNext(), number, avg);
  }
  else {
    avg = avg / number;
    cout << endl;
    cout << "Average GPA of students: " << avg << endl;
  }
  
}
