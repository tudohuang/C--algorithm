#include <iostream>
#include <vector>

bool isSafe(int row, int col, std::vector<std::vector<char>>& board, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void solveNQueen(std::vector<std::vector<char>>& board, int row, int n) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solveNQueen(board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4;
    std::vector<std::vector<char>> board(n, std::vector<char>(n, '.'));
    solveNQueen(board, 0, n);
    return 0;
}
