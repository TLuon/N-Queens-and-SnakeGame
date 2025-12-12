#include <iostream>
#include <vector>
using namespace std;

int N;
long long solutionCount = 0;
vector<int> sample;

void solveBitmask(int row, int col, int diag1, int diag2, vector<int> &pos)
{
    if (row == N)
    {
        solutionCount++;
        if (sample.empty())
            sample = pos; // luu loi giai dau tien
        return;
    }

    int freePos = (~(col | diag1 | diag2)) & ((1 << N) - 1);

    while (freePos)
    {
        int bit = freePos & -freePos;
        freePos -= bit;

        int c = __builtin_ctz(bit); // doi tu bit sang cot

        pos[row] = c;
        solveBitmask(row + 1,
                    col | bit,
                    (diag1 | bit) << 1,
                    (diag2 | bit) >> 1,
                    pos);
    }
}

void printBoard(const vector<int> &pos)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (pos[i] == j ? "Q " : ". ");
        cout << "\n";
    }
}

int main()
{
    cout << "Nhap N (toi da 20): ";
    cin >> N;

    if (N < 1 || N > 20)
    {
        cout << "N khong hop le.\n";
        return 0;
    }

    vector<int> pos(N, 0);

    solveBitmask(0, 0, 0, 0, pos);

    cout << "Tong so loi giai: " << solutionCount << "\n\n";

    if (!sample.empty())
    {
        cout << "Mot loi giai mau:\n";
        printBoard(sample);
    }

    return 0;
}
