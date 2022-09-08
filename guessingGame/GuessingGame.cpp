/*
Noam Yaffe
9/7/2022
This program will allow the user to play a random number guessing game, where the user will input a number
between 1-100, and will see whether the number they entered was too high, too low, or correct

THE THREE RULES:
1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.)
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	
	//get a random number seed
	srand(time(NULL));

	int randomNumber = 0;
	int userInput = 0;
	bool playAgain = false;
	char answer = 'y';

	cout << "Welcome to the guessing game!" << endl;

	//loop that makes the game stop depending on user input (must run at least once, hence the do-while loop)
	do {

		//reset tries
		int tries = 0;

		//get a random number
		randomNumber = 1 + (rand() % 100);

		//second loop that runs until the user guesses the correct number
		while (userInput != randomNumber) {

			tries++;

			cout << "Enter your guess (1-100): ";
			cin >> userInput;
			cout << endl;

			//conditionals regarding user input
			if (userInput > randomNumber) {
				cout << "Too high!" << endl;
			}
			else if (userInput < randomNumber) {
				cout << "Too low!" << endl;
			}
			else {
				cout << "You win! It took you " << tries << " tries to get the right number!" << endl;
			}

		}

		//if answer is y, the game will restar. If answer is n, the game will end
		cout << "Do you wish to play again? [y/n]: ";
		cin >> answer;

	} while (answer == 'y');

	cout << endl;
	cout << "The game has ended, thanks for playing!" << endl;

	return 0;

}