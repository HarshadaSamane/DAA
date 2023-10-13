#include <iostream>
using namespace std;

int main() {

        int N;

        cout << "Enter no. of Queens (N): ";
        cin >> N;

        if (N<=3) {
            cout << "no. of feasible solution!";
        }

        int board[N][N] = {};

    return 0;
}