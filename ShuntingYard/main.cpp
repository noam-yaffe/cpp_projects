#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

struct Stack {

  Node * head = NULL;

  //insert node into the stack
  void push(char c) {
    Node * newNode = new Node(c);
    newNode->next = head;
    head = newNode;
  }

  //remove the head of the stack
  void pop() {
    if (head == NULL) {
      cout << endl;
      cout << "Stack is empty" << endl;
      return;
    }
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  //look into the head of the stack
  char peak() {
    if (head == NULL) {
      return '\0';
    }
    return head->symbol;
  }

  void print() {
    Node * current = head;
    cout << endl;
    while (current != NULL) {
      cout << current->symbol;
      current = current->next;
    }
  }

};

struct Queue {

  Node * head = NULL;
  Node * tail = NULL;

  //add a node to the end of the queue
  void enqueue(char c) {
    Node * newNode = new Node(c);
    if (head == NULL) {
      head = newNode;
      tail = head;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }

  //remove the head of the queue and return its symbol
  char dequeue() {
    if (head == NULL) {
      cout << endl;
      cout << "Queue is empty." << endl;
      return '\0';
    }
    Node * temp;
    temp = head;
    head = head->next;
    char c = temp->symbol;
    delete temp;
    return c;
  }

  void print() {
    Node * current = head;
    while (current != NULL) {
      cout << current->symbol;
      current = current->next;
    }
  }

};

int main() {

  char * equation = new char[30];
  Stack stack;
  Queue queue;
  
  cout << endl;
  cout << "Welcome to the Shunting Yard Algorithm!" << endl;
  cout << endl;
  cout << "Please enter your mathematical equation (only 1 digit numbers): ";
  cin.get(equation, 30);
  cin.get();

  for (int i = 0; i < strlen(equation); i++) {
    if (equation[i] == ' ') {
      //space, do nothing
    }
    if (isdigit(equation[i]) == 1) {
      //integer, push into QUEUE
      queue.enqueue(equation[i]);
    }
    else {
      //mathematical symbol, check precedence, and push into STACK
      stack.push(equation[i]);
    }
  }

  queue.print();
  stack.print();
  
  return 0;
  
}
