#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> col; // col[i] = vi tri cot cua hau o hang i
int solutionCount = 0;

bool isSafe(int row, int c) {
    for (int i = 0; i < row; i++) {
        if (col[i] == c) return false;
        if (abs(col[i] - c) == abs(i - row)) return false;
    }
    return true;
}

void printBoard() {
    cout << "Solution " << ++solutionCount << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (col[i] == j ? "Q " : ". ");
        }
        cout << "\n";
    }
    cout << "\n";
}

void solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return;
    }
    for (int c = 0; c < N; c++) {
        if (isSafe(row, c)) {
            col[row] = c;
            solveNQueens(row + 1);
        }
    }
}

int main() {
    cout << "Nhap N (de test backtracking): ";
    cin >> N;

    col.assign(N, 0);
    solveNQueens(0);

    if (solutionCount == 0) 
        cout << "Khong co loi giai.\n";
}

