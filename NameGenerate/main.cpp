#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

  ifstream first_names("first_names.txt");
  ifstream last_names("last_names.txt");

  char * first = new char[20];
  char * last = new char[20];

  srand((unsigned) time(NULL));

  int size = 100;
  int counter = 0;
  int randomID = 0;
  int index = 0;
  
  while (first_names >> first && last_names >> last && counter != 10) {
    randomID  =((rand() % 999999) + 1);
    index = randomID % size;
    cout << first << " " << last  << ", " << randomID  << ", " << index << endl;
    counter++;
  }
  
  return 0;
  
}
