#include <iostream>
#include "Student.h"

using namespace std;

class Node{
 public:
  Student * student;
  Node * next;
  Node(Student* student);
  Node();
  ~Node();
  void setStudent(Student * student); //Sets the value of a node to a student
  Student* getStudent(); //Returns the value of a student found in a node
  void setNext(Node* next); //Sets the next node
  Node* getNext(); //Returns the next node(end of list if NULL)
};

