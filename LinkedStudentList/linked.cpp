#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

Student* makeStudent();
void add(Student* student);
void print(Node* next);

int main() {

  char input[10];

   cout << "Welcome to Student Linked List! Here are the commands you can use:" << end;
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
      Student * example = makeStudent();
      Node* current = new Node(example);
      current->getStudent()->getDescription();
      //add();
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter the ID of the student you want to remove: ";
      cin >> idToDelete;
      cin.get();
      //del(students, idToDelete);
    }
    else if (strcmp(input, "PRINT") == 0) {
      //print(students);
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
  
   //Student* example = new Student("Example", 472202, 4.00);
  Student* example2 = new Student("Example2", 472393, 3.50);
  //Node* current = new Node(example);
  Node* next = new Node(example2);

  current->setNext(next);
  current->getStudent()->getDescription();
  current = current->getNext();
  current->getStudent()->getDescription();
  
  return 0;
  
}

Student* makeStudent() {

  char name[20];
  int id;
  float gpa;
  
  cout << "Enter the name of the student (first and last):";
  cin.get(name, 20);
  cout << "Enter the student's ID: ";
  cin >> id;
  cout << "Enter the student's GPA: ";
  cin >> gpa;

  Student* student  = new Student(name, id, gpa);
  return student;
  
}

void add(Student* student) {
  
}

void print(Node* next) {

}
