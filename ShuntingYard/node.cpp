#include <iostream>
#include "node.h"

using namespace std;

//constructor
Node::Node(Node * left, Node * right, Node * next, char symbol) {
  this->left = left;
  this->right = right;
  this->next = next;
  this->symbol = symbol;
}

//char constructor
Node::Node(char symbol) {
  this->symbol = symbol;
  left = NULL;
  right = NULL;
  next = NULL;
}

Node::Node(Node * treeNode) {
  this->treeNode = treeNode;
  left = NULL;
  right = NULL;
  next = NULL;
  symbol = '\0';
}

//tree node constructor
Node::Node(Node * left, Node * right, char symbol) {
  this->left = left;
  this->right = right;
  this->treeNode = NULL;
  this->symbol = symbol;
  next = NULL;
}

//default constructor
Node::Node() {
  left = NULL;
  right = NULL;
  next = NULL;
  symbol = ' ';
}
