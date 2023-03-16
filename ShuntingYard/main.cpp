#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

int checkPrecedence(char c);

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
  char peek() {
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
  void dequeue() {
    if (head == NULL) {
      return;
    }
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  char peek() {
    if (head == NULL) {
      return '\0';
    }
    return head->symbol;
  }

  void print() {
    Node * current = head;
    while (current != NULL) {
      cout << current->symbol;
      current = current->next;
    }
  }

};

struct TreeStack {

  Node * head = NULL;
  Node * root = NULL;
  Node * left = NULL;
  Node * right = NULL;  

  void push(char c) {
    Node * newNode = new Node(c);
    if (head == NULL) {
      head = newNode;
      return;
    }
    else if (isDigit(c)) {
      newNode->next = head;
      head = newNode;
      delete temp;
    }
    //continue here... handle symbols, add dequeue method, and make the tree
  }

  Node * getRoot() {
    return root;
  }
  
};

int main() {

  char * equation = new char[30];
  Stack operators;
  Queue output;
  TreeStack tree;
  
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
    else if (isdigit(equation[i]) == 1) {
      //integer, push into QUEUE
      output.enqueue(equation[i]);
    }
    else {
      char input = equation[i];
      int ip = checkPrecedence(input);
      //mathematical symbol
      if (input == '(') {
	//left parenthesis
	operators.push(input);
      }
      else if (input == ')') {
	//right parenthesis
	char top = operators.peek();
	while (top != '\0' && top != '(') {
	  operators.pop();
	  output.enqueue(top);
	  top = operators.peek();
	}
	if (top == '(') {
	  operators.pop();
	}
      }
      else {
	char top = operators.peek();
	int tp = checkPrecedence(top);
	//any other mathematical symbol
	while (top != '\0' && top != '(' && (tp > ip || (tp == ip && input != '^'))) {
	  operators.pop();
	  output.enqueue(top);
	  top = operators.peek();
	  tp = checkPrecedence(top);
	}
	operators.push(input);
      }
    }
  }

  while (operators.peek() != '\0') {
    output.enqueue(operators.peek());
    operators.pop();
  }

  Node * root = new Node(NULL, NULL, '\0');
  makeTree(output, tree);
  
  output.print();
  operators.print();
  
  return 0;
  
}

int checkPrecedence(char c) {

  if (c == '+' || c == '-') {
    return 1;
  }
  else if (c == '*' || c == '/') {
    return 2;
  }
  else if (c == '^') {
    return 3;
  }
  else if (c == '(' || c == ')') {
    return 4;
  }
  else {//probably a null value
    return 0;
  }
  
}

void makeTree(Queue output, TreeStack &tree) {

  char c = output.peek();
  
  while (c != '\0') {
    if (isDigit(c)) {
      //is a digit
      tree.push(c);
    }
    else {
      //is a mathematical symbol
    }
    c = output.peek();
  }

}
