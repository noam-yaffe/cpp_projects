#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node {
public:
  Node(Student* student);
  Node();
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
private:
  Student* student;
  Node* next;
};
