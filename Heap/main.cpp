#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void fileGenerator(int * &heap);
void manualGenerator(int * &heap);
void insert(int * &heap, int num, int counter);

int main() {

  int * heap = new int[101];
  int answer = 0;
  bool cont = false;
  cout << "Welcome to Heap!" << endl;
  do {
    cout << "Type 1 to generate the numbers with a file, type 2 to generate them manually:";
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
    cout << counter + 1 << ": " << number << endl;
    insert(heap, number, counter);
    counter++;
  }
  
}

void manualGenerator(int * &heap) {

  
  
}

void insert(int * &heap, int num, int counter) {

  if (counter == 0) {
    heap[1] = num;
  }
  else {
    
  }
  
}
