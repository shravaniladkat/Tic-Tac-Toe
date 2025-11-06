#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    // Check row on left
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Upper diagonal on left
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Lower diagonal on left
    for (int i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

void solveNQUtil(vector<vector<int>> &board, int col, int N,
                 vector<vector<vector<int>>> &solutions) {
    if (col >= N) {
        solutions.push_back(board);   // store solution
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;              // place queen
            solveNQUtil(board, col + 1, N, solutions);
            board[i][col] = 0;              // backtrack
        }
    }
}

void solveNQ(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<vector<int>>> solutions;

    solveNQUtil(board, 0, N, solutions);

    if (solutions.empty()) {
        cout << "Solution does not exist\n";
    } else {
        cout << "Total solutions found: " << solutions.size() << "\n\n";

        for (auto &solution : solutions) {
            printSolution(solution, N);
            cout << "\n";
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of Queens (N): ";
    cin >> N;

    solveNQ(N);
    return 0;
}