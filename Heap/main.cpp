#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

void fileGenerator(int * &heap);
void manualGenerator(int * &heap);
void insert(int * &heap, int num);
int findParent(int * &heap, int index);
void print(int * heap, int index, int layer);
int findLeft(int * heap, int input);
int findRight(int * heap, int input);
void removeRoot(int * &heap);

int main() {
  int * heap = new int[101];
  for (int i = 0; i < 101; i++) {
    heap[i] = 0;
  }
  int answer = 0;
  bool cont = false;
  cout << "Welcome to Heap!" << endl;
  do {
    cout << "Type 1 to generate the numbers with a file, type 2 to generate them manually: ";
    cin >> answer;

    if (answer == 1) {
      fileGenerator(heap);
      cont = true;
    }
    else if (answer == 2) {
      manualGenerator(heap);
      cont = true;
    }
    else {
      cout << "You didn't enter a valid choice! Try again." << endl;
    }
  } while(!cont);

  cout << "=======================" << endl;
  cout << endl;
  cout << "AFTER ROOT REMOVEAL" << endl;
  removeRoot(heap);
  print(heap, 1, 0);
  
}

void fileGenerator(int * &heap) {

  ifstream numbers("numbers.txt");
  srand(time(NULL));
  int num = 0;
  vector<int> nums;
  
  while (!numbers.eof()) {
    numbers >> num;
    nums.push_back(num);
  }

  int randomIndex = 0;
  int counter = 0;
  int number = 0;

  while (counter != 50) {
    randomIndex = (rand() % 999) + 1;
    number = nums.at(randomIndex);
    //cout << counter + 1 << ": " << number << endl;
    insert(heap, number);
    counter++;
  }

  cout << endl;
  print(heap, 1, 0);
  
}

//generate the heap with user input
void manualGenerator(int * &heap) {

  int input = 0;
  
  cout << "Enter numbers separated by spaces: ";
  
  while (cin.eof()) {
    cin >> input;
    insert(heap, input);
  }
  
}

//generate the heap with file input
void insert(int * &heap, int num) {

  int index = 0;
  
  if (heap[1] == 0) {
    heap[1] = num;
  }
  else {
    for (int i = 1; i < 101; i++) {
      if (heap[i] == 0) {
	heap[i] = num;
	index = i;
	break;
      }
    }
  }

  int parentIndex = findParent(heap, index);
  while (parentIndex != -1 && heap[index] > heap[parentIndex]) {
    int temp = heap[index];
    heap[index] = heap[parentIndex];
    heap[parentIndex] = temp;
    index = parentIndex;
    parentIndex = findParent(heap, index);
  }
  
}

int findParent(int * &heap, int index) {

  if (index == 1) {
    return -1;
  }
  else {
    return floor(index / 2);
  }
  
}

//using the inorder tree traversal algorithm
void print(int * heap, int index, int layer) {

  if (index == -1 || heap[index] == 0) {
    return;
  }

  print(heap, findLeft(heap, index), layer + 1);

  for (int i = 0; i < layer; i++) {
    cout << "    ";
  }
  cout << heap[index] << endl;

  print(heap, findRight(heap, index), layer + 1);
  
}

int findLeft(int * heap, int input) {

  int index = input * 2;
  
  if (heap[index] != 0 && index != 100) {
    return index;
  }
  else {
    return -1;
  }
  
}

int findRight(int * heap, int input) {

  int index = (input * 2) + 1;

  if (heap[index] != 0 && index != 100) {
    return index;
  }
  else {
    return -1;
  }

}

void removeRoot(int * &heap) {

  int index = 1;
  int leftChild = 0;
  int rightChild = 0;
  int swapper = 0;
  int temp = 0;
  
  while (index < 101) {

    leftChild = findLeft(heap, index);
    rightChild = findRight(heap, index);

    //both children exist
    if (leftChild != -1 && rightChild != -1) {
      if (heap[leftChild] > heap[rightChild]) {
	swapper = leftChild;
      }
      else {
	swapper = rightChild;
      }
    }
    //only right child exists
    else if (rightChild != -1 && leftChild == -1) {
      swapper = rightChild;
    }
    //only left child exists
    else if (leftChild != -1 && rightChild == -1) {
      swapper = leftChild;
    }
    //no children exist, we reached the end of the tree
    else {
      heap[index] = 0;
      break;
    }

    temp = heap[index];
    heap[index] = heap[swapper];
    heap[swapper] = temp;
    index = swapper;
    
  }

  heap[swapper] = 0;
  
}
