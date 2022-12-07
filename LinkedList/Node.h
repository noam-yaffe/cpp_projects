#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node {
public:
  Node(Student*);
  Node();
  ~Node();
  Node* getNext();
  void setStudent(Student* student);
  Student* getStudent();
  void setNext(Node*);
private:
  Student* student;
  Node* next;
};
