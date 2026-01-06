#include <iostream>
#include <vector>
using namespace std;

int n;
int solutionCount = 0;
vector<int> pos;  // pos[r] = c: hang r dat hau tai cot c

void printSolution() {
    solutionCount++;
    cout << "Solution " << solutionCount << ":\n";

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (pos[r] == c) cout << " Q ";
            else cout << " . ";
        }
        cout << "\n";
    }
    cout << "---------------------\n";
}
void solveBitmask(int r, int colMask, int diag1Mask, int diag2Mask) {
    if (r == n) {
        printSolution();
        return;
    }

    // Tinh cac vi tri khi dung
    int available = ((1 << n) - 1) & ~(colMask | diag1Mask | diag2Mask);

    while (available) {
        int bit = available & -available;   // lay 1 vi tri hop le
        available -= bit;

        int c = __builtin_ctz(bit);  // chuyen bit sang chi so cot

        pos[r] = c;


        solveBitmask(
            r + 1,
            colMask | bit,
            (diag1Mask | bit) << 1,
            (diag2Mask | bit) >> 1
        );
    }
}

int main() {
    cout << "Nhap N: ";
    cin >> n;

    pos.resize(n);

    solveBitmask(0, 0, 0, 0);

    cout << "Tong so loi giai: " << solutionCount << endl;

    return 0;
}

