#include <iostream>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Student* student);
void print(Node* next);

int main() {

  Student* example = new Student("Example");
  Student* example2 = new Student("Example2");
  Node* current = new Node(example);
  Node* next = new Node(example2);

  current->setNext(next);
  cout << current->getStudent()->getName() << endl;
  current = current->getNext();
  cout << current->getStudent()->getName() << endl;
  
  return 0;
  
}

void add(Student* student) {
  
}

void print(Node* next) {

}
