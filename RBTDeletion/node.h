#include <iostream>

using namespace std;

class Node {//node class
 public:
  int data;
  Node * right;
  Node * left;
  Node * parent;
  char color;//will either be 'R' or 'B'
  Node(int data, Node * right, Node * left, Node * parent, char color);
  Node();
  ~Node();
};
