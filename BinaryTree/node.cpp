#include <iostream>
#include "node.h"

using namespace std;

Node::Node(int data, Node * right, Node * left) {
  this->data = data;
  this->right = right;
  this->left = left;
}

Node::Node() {
  data = 0;
  right = NULL;
  left = NULL;
}

Node::~Node() {
  delete right;
  delete left;
}
