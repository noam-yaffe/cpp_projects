#include <iostream>
#include <cstring>

using namespace std;

int main() {

  int i = 0;
  int num = 0;
  int current = 0;
  int highest = 0;
  int quit = 0;

  do {
    cout << "# of numbers you want to enter: " << endl;
    cin >> num;
  
    cout << "Enter the series of numbers separated by numbers below:" << endl;
  
    while (i < num) {
      cin >> current;
      if (current > highest) {
	highest = current;
      }
      i++;
    }

    cout << "Highest number: " << highest << endl;

    cout << "Enter 1 if you want to go again, enter 2 to quit: ";
    cin >> quit;

    cin.get();
    i = 0;
    highest = 0;
  } while(quit != 2);

  cout << "This program is over.";
  
  return 0;
  
}
