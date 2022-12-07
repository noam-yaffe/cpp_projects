#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

//constructor
Node::Node(Student* student) {
  this->student = student;
}

//default constructor
Node::Node() {
  //should never be called
}

//destructor
Node::~Node() {
  delete student;
  next = NULL;
}

//get next Node pointer
Node* Node::getNext() {
  return NULL;
}

//set student pointer
void Node::setStudent(Student* student) {
  this->student = student;
}

//get student pointer
Student* Node::getStudent() {
  return NULL;
}

//set the next pointer to the corresponding Node pointer
void Node::setNext(Node* next) {
  this->next = next;
}
