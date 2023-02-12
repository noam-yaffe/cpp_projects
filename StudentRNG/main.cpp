#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main() {

  int a = 0;
  
  ifstream firstFile;
  firstFile.open("first_names.txt");
  ifstream lastFile;
  lastFile.open("last_names.txt");
  char * first_names[100];
  char * last_names[100];

  if (firstFile.is_open()) {
    cin.rdbuf(firstFile.rdbuf());
    cin >> first_names[a];
  }

  cout << "First name: " << first_names[a] << endl;

  //  for (int i = 0; i < 100; i++) {
  //    cout << first_names[i] << " " << last_names[i] << endl
  //  }
  
  firstFile.close();
  lastFile.close();
  
  return 0;
  
}
