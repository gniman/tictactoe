#include <iostream>

using namespace std;

char board[3][3]; // 2D array initialization

// Function to initialize the new game board with spaces
void new_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void board_printer() // Function to print the game board
{  
  cout << endl;
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "---+---+---" << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "---+---+---" << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
  cout << endl;
}

int winner_checker(char player) // Function to check if a player has won
{ 
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }
  return 0;
}

void play_game() // Function to play the game
{
  int row, col;
  char player = 'X';
  int count = 0;
  new_board();
  while (1) {
    cout << "Player " << player << "'s turn:" << endl;
    cout << "Enter row (1-3): ";
    cin >> row;
    cout << "Enter column (1-3): ";
    cin >> col;
    if (row < 1 || row > 3 || col < 1 || col > 3) {
      cout << "Invalid input. Try again." << endl;
      continue;
    }
    if (board[row-1][col-1] != ' ') {
      cout << "That space is already occupied. Try again." << endl;
      continue;
    }
    board[row-1][col-1] = player;
    board_printer();
    if (winner_checker(player)) {
      cout << "Player " << player << " wins!" << endl;
      break;
    }
    count++;
    if (count == 9) {
      cout << "It's a tie!" << endl;
      break;
    }
    player = (player == 'X') ? 'O' : 'X';
  }
}

int main() // Main function to start the program
{
  play_game();
  return 0;
}
