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

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    drawBoard(board);
    return 0;
}
