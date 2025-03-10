#include <iostream>

void drawBoard(char board[3][3])
{
    std::cout << "-------------\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player
        && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player
        && board[2][0] == player)
        return true;
    return false;
}

void gameLoop() {

}
int main() {
    // Initialize the board and players
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };
    char player = 'X';
    int row, col;
    int turn; // Declare turn here

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    // Game loop
    for (turn = 0; turn < 9; turn++) {
        // Draw the board
        drawBoard(board);

        // Prompt for valid input
        while (true) {
            std::cout << "Player " << player
                 << ", enter row (0-2) and column (0-2): ";
            std::cin >> row >> col;

            if (board[row][col] != ' ' || row < 0 || row > 2
                || col < 0 || col > 2) {
                std::cout << "Invalid move. Try again.\n";
            }
            else {
                break; // Valid input, exit the loop.
            }
        }

        // Make the move
        board[row][col] = player;

        // Check for a win after making a move
        if (checkWin(board, player)) {
            drawBoard(board);
            std::cout << "Player " << player << " wins!\n";
            break; // Exit the loop after a win.
        }

        // Switch to the other player
        player = (player == 'X') ? 'O' : 'X';
    }

    // End of the game
    drawBoard(board);

    // Check for a draw
    if (turn == 9 && !checkWin(board, 'X')
        && !checkWin(board, 'O')) {
        std::cout << "It's a draw!\n";
    }

    return 0;
}
