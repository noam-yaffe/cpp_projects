#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

//constructor
Node::Node(Student* student) {
  this->student = student;
  next = NULL;
}

//default constructor
Node::Node() {
  //should never be called
  next = NULL;
}

//destructor
Node::~Node() {
  delete student;
  next = NULL;
}

//get next Node pointer
Node* Node::getNext() {
  return next;
}

//get student pointer
Student* Node::getStudent() {
  return student;
}

//set the next pointer to the corresponding Node pointer
void Node::setNext(Node* next) {
  this->next = next;
}

void Node::setStudent(Student * student) {
  this->student = student;
}
