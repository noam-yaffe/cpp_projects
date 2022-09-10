/*
Noam Yaffe
9/9/2022
This project checks to see if the input given by the user is a palindrome.
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {

  bool isPalindrome = true;
  char inputStr[81];
  char sanitizedStr[81];

  //max num of inputted chars is 80
  cin.get(inputStr, 81);
  cin.get();
  int count = 0;
  
  //puts characters from input into the new array only if they alphanumeric (letters or numbers)
  for (int i = 0; i < strlen(inputStr); i++) {

    if (isalnum(inputStr[i])) {
      char c = tolower(inputStr[i]);
      sanitizedStr[count] = c;
      count++;
    }

  }
  
  //make sure to place a null terminator or the program will go into memory it isn't supposed to
  sanitizedStr[count] = '\0';
  
  //iterates through the new char array with two pointers, one at the start and one at the end,
  //where they will be moving towards each other and comparing the indexes they are on
  for (int i = 0; i < strlen(sanitizedStr); i++) {

    //if the indexes the pointers are on do not contain the same characters, the input was not a palindrome
    if (sanitizedStr[i] != sanitizedStr[strlen(sanitizedStr) - 1 - i]) {
      isPalindrome = false;
      break;
    }

  }

  //final condition that decides what to output to the user
  if (isPalindrome) {
    cout << "Palindrome." << endl;
  }
  else {
    cout << "Not a palindrome." << endl;
  }

  return 0;

}
