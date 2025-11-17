#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') return false;
    }
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }
    return true;
}

bool solveNQueens(vector<string>& board, int row, int n) {
    if(row == n) return true;
    
    for(int col = 0; col < n; col++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            if(solveNQueens(board, row + 1, n)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    if(solveNQueens(board, 0, n)) {
        for(string& row : board) cout << row << endl;
    }
    return 0;
}