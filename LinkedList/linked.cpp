#include <iostream>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Student* student);
void print(Node* next);

Node* head = NULL;

int main() {

  Student* noam = new Student("Noam");
  Student* adi = new Student("Adi");
  Student* daphna = new Student("Daphna");

  add(noam);
  print(head);
  add(adi);
  print(head);
  add(daphna);
  print(head);
  
  return 0;
  
}

void add(Student* student) {
  
}

void print(Node* next) {

}
