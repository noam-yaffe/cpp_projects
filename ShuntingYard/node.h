#include <iostream>

using namespace std;

class Node{
 public:
  Node * left;
  Node * right;
  Node * next;
  char symbol;
  Node(Node * left, Node * right, Node * next, char symbol);
  Node(char symbol);
  Node();
};
