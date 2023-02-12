#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student * student){
  this->student = student;
  next = NULL;
}

Node::Node() {
  student = NULL;
}

Node::~Node(){
  delete student;
  next = NULL;
}

//Sets the value of the node to a student
void Node::setStudent(Student * student){
  this->student = student;
}

//Returns the value of a student found in a node
Student* Node::getStudent(){
  return student;
}

//Sets the next node
void Node::setNext(Node* next){
  this->next = next;
}

//Returns the next node (end of list if NULL)
Node* Node::getNext(){
  return next;
}
