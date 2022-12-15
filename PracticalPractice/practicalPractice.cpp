#include <iostream>
#include <cstring>

using namespace std;

int main() {

  int result = 1;
  int number = 0;
  int i = 0;

  cout << "Enter a series of seven numbers below:" << endl;
  
  while (i < 7) {
    cin >> number;
    if (number % 3 != 0 && number % 5 != 0) {
      result = result * number;
    }
    else {
      //don't multiply it
    }
    i++;
  }

  cout << "Result: " << result << endl;
  
  return 0;
  
}
