#include <iostream>
#include <cstring>

using namespace std;

int main() {

  char * word = new char[10];
  char * result = new char[10];
  int j = 0;
  
  cout << "Enter a word: ";
  cin.getline(word, 10);

  for (int i = strlen(word) - 1; i > -1; i--) {
    if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o'
        && word[i] != 'u') {
      result[j] = word[i];
      j++;
    }
    else {
      //do nothing
    }
  }

  cout << result << endl;
  
  return 0;
  
}
