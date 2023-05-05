#include <iostream>
#include "node.h"

using namespace std;

Node::Node(int data, Node * right, Node * left, Node * parent, char color) {//node constructor: data, children, and parent
  this->data = data;
  this->right = right;
  this->left = left;
  this->parent = parent;
  this->color = color;
}

Node::Node() {//default constructor: node color set to black ('B') by default
  data = 0;
  right = NULL;
  left = NULL;
  parent = NULL;
  color = 'B';
}

Node::~Node() {
  //nothing
}
