#include <iostream>
#include <cstring>

using namespace std;

int main() {

  bool isPalindrome = true;
  char inputStr[81];
  char sanitizedStr[81];

  cin.get(inputStr, 81);
  cin.get();
  int count = 0;

  for (int i = 0; i < strlen(inputStr); i++) {

    if (isalnum(inputStr[i])) {
      char c = tolower(inputStr[i]);
      sanitizedStr[count] = c;
      count++;
    }

  }

  sanitizedStr[count] = '\0';

  for (int i = 0; i < strlen(sanitizedStr); i++) {

    if (sanitizedStr[i] != sanitizedStr[strlen(sanitizedStr) - 1 - i]) {
      isPalindrome = false;
      break;
    }

  }

  if (isPalindrome) {
    cout << "Palindrome." << endl;
  }
  else {
    cout << "Not a palindrome." << endl;
  }

  return 0;

}
