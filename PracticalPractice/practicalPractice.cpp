#include <iostream>
#include <cstring>

using namespace std;

int main() {

  char * word = new char[10];
  char c = ' ';
  
  cout << "Enter a word: ";
  cin.getline(word, 10);

  if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o'
       || word[0] == 'u') && (word[1] == 'a' || word[1] == 'e' ||
			      word[1] == 'i' || word[1] == 'o' ||
			      word[1] == 'u')) {
    c = word[0];
    word[0] = word[1];
    word[1] = c;
  }

  cout << word << endl;
  
  return 0;
  
}
