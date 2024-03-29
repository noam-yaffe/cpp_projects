//Noam Yaffe, Period 7
//3/17/2023
//The Shunting Yard Algorithm implements three data structures -- Queue, Stack, and Binary Expression Tree -- to convert
//an inputted mathematical equation into infix, prefix, and postfix notations.
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

int checkPrecedence(char c);

struct Stack {

  Node * head = NULL;

  //inserts node into the stack
  void push(char c) {
    Node * newNode = new Node(c);
    if (head == NULL) {
      head = newNode;
      return;
    }
    newNode->next = head;
    head = newNode;
  }

  //removes the head of the stack
  void pop() {
    if (head == NULL) {
      return;
    }
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  //looks into and returns the head of the stack
  char peek() {
    if (head == NULL) {
      return '\0';
    }
    return head->symbol;
  }

  //prints out the stack
  void print() {
    Node * current = head;
    while (current != NULL) {
      cout << current->symbol;
      current = current->next;
    }
    cout << endl;
  }

};


struct TreeStack {

  Node * head = NULL;

  //inserts node into the stack
  void push(Node * n) {
    Node * newNode = new Node(n);
    if (head == NULL) {
      head = newNode;
      return;
    }
    newNode->next = head;
    head = newNode;
  }

  //removes the head of the stack
  void pop() {
    if (head == NULL) {
      return;
    }
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  //looks into and returns the head of the stack
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

  //adds a node to the end of the queue
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

  //removes the head of the queue and return its symbol
  void dequeue() {
    if (head == NULL) {
      return;
    }
    Node * temp;
    temp = head;
    head = head->next;
    delete temp;
  }

  //looks into and returns the head of the queue
  char peek() {
    if (head == NULL) {
      return '\0';
    }
    return head->symbol;
  }

  //prints out the queue
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
void printExpressionTree(Node * current, int layer);
void infix(Node * current);
void prefix(Node * current);
void postfix(Node * current);

int main() {

  char * equation = new char[30];
  char * input = new char[20];
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

  //add the rest of the stack into the queue
  while (operators.peek() != '\0') {
    output.enqueue(operators.peek());
    operators.pop();
  }

  //print out the queue (should already be in postfix notation)
  output.print();

  Node * root = makeTree(output);
  cout << endl;
  //print expression tree
  cout << "Expression Tree:" << endl;
  printExpressionTree(root, 0);

  //choose output method
  cout << endl;
  cout << "Enter \"INFIX\" \"PREFIX\" \"POSTFIX\": ";
  cin.getline(input, 20);

  if (strcmp(input, "INFIX") == 0) {
    //infix notation
    infix(root);
  }
  else if (strcmp(input, "PREFIX") == 0) {
    //prefix notation
    prefix(root);
  }
  else if (strcmp(input, "POSTFIX") == 0) {
    //postfix notation
    postfix(root);
  }
  else {
    //invalid user input
    cout << "Invalid input" << endl;
  }
  
  return 0;
  
}

//check the precedence of a mathematical symbol
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

//creates the expression tree using the queue and tree stack
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
  //When we're done, we are left with a single node in treeStack
  //which is the tree root
  Node * root = treeStack.peek();
  return root;
}

//prints out the expression tree using InOrder tree traversal
void printExpressionTree(Node * current, int layer) {

  if (current == NULL) {
    return;
  }

  printExpressionTree(current->right, layer + 1);

  for (int i = 0; i < layer; i++) {
    cout << "    ";
  }
  cout << current->symbol << endl;

  printExpressionTree(current->left, layer + 1);
  
}

//prints tree in infix notation
void infix(Node * current) {

  if (current == NULL) {
    return;
  }

  infix(current->left);

  cout << current->symbol;

  infix(current->right);

}

//prints tree in prefix notation
void prefix(Node * current) {

  if (current == NULL) {
    return;
  }

  cout << current->symbol;
  
  prefix(current->left);

  prefix(current->right);

}

//prints tree in postfix notation
void postfix(Node * current) {

  if (current == NULL) {
    return;
  }

  postfix(current->left);

  postfix(current->right);

  cout << current->symbol;
  
}
