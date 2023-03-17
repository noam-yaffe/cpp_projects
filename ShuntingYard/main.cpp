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
    if (head == NULL) {
      head = newNode;
      return;
    }
    newNode->next = head;
    head = newNode;
  }

  //remove the head of the stack
  void pop() {
    if (head == NULL) {
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

  Node * peekNode() {
    return head;
  }

  void print() {
    Node * current = head;
    //cout << endl;
    while (current != NULL) {
      cout << current->symbol;
      current = current->next;
    }
    cout << endl;
  }

};


struct TreeStack {

  Node * head = NULL;

  //insert node into the stack
  void push(Node * n) {
    Node * newNode = new Node(n);
    if (head == NULL) {
      head = newNode;
      return;
    }
    newNode->next = head;
    head = newNode;
  }

  //remove the head of the stack
  void pop() {
    if (head == NULL) {
      return;
    }
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  //look into the head of the stack
  Node * peek() {
    if (head == NULL) {
      return NULL;
    }
    return head->treeNode;
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
    cout << endl;
  }

};

Node * makeTree(Queue output);
void printInOrder(Node * current, int layer);

int main() {

  char * equation = new char[30];
  Stack operators;
  Queue output;
  
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

  output.print();
  //operators.print();

  Node * root = makeTree(output);
  cout << "root: " << root->symbol << endl;
  cout << "left: " << root->left->symbol << endl;
  cout << "right: " << root->right->symbol << endl;
  cout << endl;
  printInOrder(root, 0);
  
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

Node * makeTree(Queue output) {
  char symbol = output.peek();
  TreeStack treeStack;
  while (symbol != '\0') {
    if (isdigit(symbol)) {
      Node * treeNode = new Node(symbol);
      treeStack.push(treeNode);
    }
    else {
      // Symbol is an operator
      Node * rightChild = treeStack.peek();
      treeStack.pop();
      Node * leftChild = treeStack.peek();
      treeStack.pop();
      Node * operatorNode = new Node(leftChild, rightChild, symbol);
      treeStack.push(operatorNode);
    }
    output.dequeue();
    symbol = output.peek();
  }
  // When we're done, we are left with a single node in treeStack
  // which is the tree root
  Node * root = treeStack.peek();
  return root;
}

void printInOrder(Node * current, int layer) {

  if (current == NULL) {
    return;
  }

  printInOrder(current->right, layer + 1);

  for (int i = 0; i < layer; i++) {
    cout << "    ";
  }
  cout << current->symbol << endl;

  printInOrder(current->left, layer + 1);
  
}
