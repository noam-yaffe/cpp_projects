/*
09/27/2022
Noam Yaffe
In this program the user is able to play a two-person TicTacToe game! each player has a symbol, X or O, and must get three in a row,
column, or diagnol to gain a point. The game ends when the user decides he doesn't want to play another round.
*/
#include <iostream>

using namespace std;

//methods
void resetBoard(char board[3][3]);
void drawBoard(char board[3][3]);
bool checkWinX(char board[3][3], int &xWins);
bool checkWinO(char board[3][3], int &oWins);

int main() {

  char board[3][3];
  char symbols[3] = {' ', 'X', 'O'};
  int turn = 0;
  char c = ' ';
  int row = 0;
  int column = 0;
  bool cont = false;
  int xWins = 0;
  int oWins = 0;
  bool xWin = false;
  bool oWin = false;
  int playAgain = 0;
  int round = 0;

  //printing out the board initially
  cout << "Welcome to Tic Tac Toe!" << endl;
  cout << "Player 1 is X, and player 2 is O" << endl;
  cout << "This is how the board looks like:" << endl;
  
  resetBoard(board);

  //the actual game
  while (playAgain == 0 || playAgain == 1) {

    round++;
    cout << endl;
    drawBoard(board);
    
    if (turn == 0 || turn == 2) {
      turn = 1;
    }
    else {
      turn = 2;
    }

    //getting user input
    cout << endl;
    cout << "Player " << turn << ", please enter the row letter: ";
    cin >> c;
    row = (int)c - 97;
    cout << "Enter the column number: ";
    cin >> column;
    column--;

    //entering user input unless the spot is already taken
    if (board[row][column] != 'X' && board[row][column] !=   'O') {
      board[row][column] = symbols[turn];
    }
    else {
      //user input is wrong
      while (!cont) {
        cout << endl;
        cout << "Spot is already taken. Try again." << endl;
        cout << "Player " << turn << ", please enter the row letter: ";
        cin >> c;
        row = (int)c - 97;
        cout << "Enter the column number: ";
        cin >> column;
        column--;

        //only inputting the symbol into the board if the user input if the spot is blank
        if (board[row][column] != 'X' && board[row][column] != 'O') {
          board[row][column] = symbols[turn];
          cont = true;
        }
      }
    }
    cont = false;

    //checking for a win
    xWin = checkWinX(board, xWins);
    oWin = checkWinO(board, oWins);

    //printing out scores if somebody won and asking the user if they want to quit
    if (xWin == true || oWin == true || round == 9) {
       cout << endl;
       drawBoard(board);
       cout << endl;
       resetBoard(board);
       if (round == 9) {
	 cout << "It's a tie!" << endl;
       }
       cout << "X wins: " << xWins << endl;
       cout << "O wins: " << oWins << endl;
       cout << "Enter 1 to continue playing, enter 2 to quit: ";
       cin >> playAgain;
       xWin = false;
       oWin = false;
       turn = 0;
    }
    
  }

  cout << "Game has ended. Thanks for Playing!" << endl;
 
}

//resets the board to blank

void resetBoard(char board[3][3]) {

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = ' ';
    }
  }

}

//drawing the board with its components (if there are any)
void drawBoard(char board[3][3]) {

  cout << "  1  2  3" << endl;
  cout << "a " << board[0][0] << "  " << board[0][1] << "  " << board[0][2] << endl;
  cout << "b " << board[1][0] << "  " << board[1][1] << "  " << board[1][2] << endl;
  cout << "c " << board[2][0] << "  " << board[2][1] << "  " << board[2][2] << endl;

}

//checking all winning conditions for X (row, column, or diagonal)
bool checkWinX(char board[3][3], int &xWins) {

  if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
    cout << "X wins!" << endl;
    xWins++;
    return true;
  }
  else {
    return false;
  }
 
}

//checking all winning conditions for O (row, column, or diagonal)
bool checkWinO(char board[3][3], int &oWins) {

  if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
    cout << "O wins!" << endl;
    oWins++;
    return true;
  }
  else {
    return false;
  }
 
}
