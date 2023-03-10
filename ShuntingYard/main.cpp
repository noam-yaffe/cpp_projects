#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

struct stack {

  Node * head;

  //insert node into the stack
  push(Node * newNode) {
    newNode->next = head;
    head = newNode;
  }

  //remove the head of the stack
  void pop() {
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  //look into the head of hte stack
  void peak() {
    cout << endl;
    cout << head->symbol << endl;
  }

};

struct queue {

  Node * head;

  void enqueue(Node * newNode) {
    Node * current = head;
    bool done = false;
    while (!done) {
      if (current->next == NULL) {
        current->next = newNode;
        newNode->next = NULL;
        done = true;
      }
      else {
        current = current->next;
      }
    }
  }

  void dequeue() {
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

};

int main() {

  char * equation = new char[30];
  
  cout << endl;
  cout << "Welcome to the Shunting Yard Algorithm!" << endl;
  cout << endl;
  cout << "Please enter your mathematical equation (only 1 digit numbers): ";
  cin.get(equation, 30);
  cin.get();

  Node * temp = new Node (NULL, NULL, NULL, ' ');
  
  for (int i = 0; i < strlen(equation); i++) {
    if (equation[i] == ' ') {
      //space, do nothing
    }
    if (isdigit(equation[i]) == 1) {
      //integer, push into QUEUE
      temp->symbol = equation[i];
      queue.enqueue(temp);
    }
    else {
      //mathematical symbol, check precedence, and push into STACK
      temp->symbol = equation[i];
      stack.push(temp);
    }
  }

  //stack.print();
  //queue.print();
  
  return 0;
  
}
