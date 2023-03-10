#include <iostream>
#include "node.h"

using namespace std;

Node::Node(Node * left, Node * right, Node * next, char symbol) {
  this->left = left;
  this->right = right;
  this->next = next;
  this->symbol = symbol;
}

Node::Node() {
  left = NULL;
  right = NULL;
  symbol = ' ';
}

Node::~Node(){
  delete right;
  delete left;
}
