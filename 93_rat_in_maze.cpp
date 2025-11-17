#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& maze, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol, int n) {
    if(x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return true;
    }
    
    if(isSafe(maze, x, y, n)) {
        sol[x][y] = 1;
        if(solveMaze(maze, x + 1, y, sol, n)) return true;
        if(solveMaze(maze, x, y + 1, sol, n)) return true;
        sol[x][y] = 0;
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    vector<vector<int>> sol(n, vector<int>(n, 0));
    
    if(solveMaze(maze, 0, 0, sol, n)) {
        for(auto& row : sol) {
            for(int x : row) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}