#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node * right;
  Node * left;
  Node(int data, Node * right, Node * left);
  Node();
  ~Node();
};
