#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int m[n + 1][n + 1];

    // Initialize diagonal
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // Dynamic Programming
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] +
                           m[k + 1][j] +
                           p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    // Print DP Table
    cout << "\nDynamic Programming Table:\n\n";

    cout << "     ";
    for (int j = 1; j <= n; j++)
        cout << "M" << j << "\t";

    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << "M" << i << "   ";

        for (int j = 1; j <= n; j++) {
            if (j < i)
                cout << "-\t";
            else
                cout << m[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nMinimum number of scalar multiplications = "
         << m[1][n] << endl;

    return 0;
}
