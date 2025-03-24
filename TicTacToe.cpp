#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    char symbol;
    string name;
public:
    // constructor
    Player(char smb = 'X', const string &n = "Unnamed Player") {
        symbol = smb;
        name = n;
    }

    // getters
    char getSymbol() const {
        return symbol;
    }
    string getName() const {
        return name;
    }
};

class Board {
private:
    char grid[3][3];
    int nr_filledCells;
public:
    // constructor
    Board() {
        nr_filledCells = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
    }
    // method to display the board
    void showBoard() const {
        cout << " -------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << " | ";
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j] << " | ";
            }
            cout << endl << " -------------" << endl;
        }
    }

    // method to check if a move is valid
    bool isValidMove(int line, int col) const {
        return (0 <= line && line < 3 && 0 <= col && col < 3 && grid[line][col] == ' ');
    }

    // method to make a move
    void makeMove(int line, int col) {
        if (nr_filledCells % 2) {
            grid[line][col] = '0';
        }
        else {
            grid[line][col] = 'X';
        }
        nr_filledCells++;
    }

    // method to check for a win
    bool isWin() const {
        // check diagonals
        if ((grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != ' ') || (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != ' ')) {
            return true;
        }

        // check rows and columns
        for (auto i = 0; i < 3; i++) {
            if ((grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] && grid[i][0] != ' ') || (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i] && grid[0][i] != ' ')) {
                return true;
            }
        }

        return false;
    }

    // method to check if the board is full
    bool isTie() const {
        return nr_filledCells == 9;
    }

    // getter
    int getFilledCells() const {
        return nr_filledCells;
    }
};

class TicTacToeGame {
private:
    Board board;
    Player player1, player2;
    int currentPlayerIndex;
public:
    // constructor
    TicTacToeGame() {
        string player_name;
        currentPlayerIndex = 1;
        cout << "Enter Player1 name: ";
        cin >> player_name;
        Player player('X', player_name);
        player1 = player;

        cout << "Enter Player2 name: ";
        cin >> player_name;
        Player playerr('0', player_name);
        player2 = playerr;
    }

    // Method to get the current player
    Player& getCurrentPlayer() {
        if (currentPlayerIndex == 1) return player1;
        else return player2;
    }

    // Method to switch turns
    void switchTurns() {
        currentPlayerIndex = currentPlayerIndex == 1 ? 2 : 1;
    }

    // Play the game!!
    void playTheGame() {
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        int line, col;
        while (!board.isTie()) {
            board.showBoard();
            Player& currentPlayer = getCurrentPlayer();

            while(true) {
                cout << "Player " << currentPlayer.getName() << " (" << currentPlayer.getSymbol() << "), enter row (1-3) and column (1-3): ";
                cin >> line >> col;
                line--; col--;

                if (board.isValidMove(line, col)) {
                    break;
                }
                else {
                    cout << "Invalid move. Please try again. \n";
                }
            }
            board.makeMove(line, col);

            if (board.isWin()) {
                board.showBoard();
                cout << "Player " << currentPlayer.getName() << " wins! \n";
                return;
            }
            switchTurns();
        }
        board.showBoard();
        cout << "It's a tie! \n";
    }
};

int main() {
    // Creating game object
    TicTacToeGame game;

    // Starting the game
    game.playTheGame();
    return 0;
}
