#include <iostream>
#include <vector>
using namespace std;

class ZeroOneKnapsack {
public:
    void solve(vector<int>& wt, vector<int>& val, int W, int N) {
        const int NEGATIVE_INFINITY = INT_MIN;
        vector<vector<int>> m(N + 1, vector<int>(W + 1));
        vector<vector<int>> sol(N + 1, vector<int>(W + 1));

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= W; j++) {
                int m1 = m[i - 1][j];
                int m2 = NEGATIVE_INFINITY;
                if (j >= wt[i])
                    m2 = m[i - 1][j - wt[i]] + val[i];
                m[i][j] = max(m1, m2);
                sol[i][j] = m2 > m1 ? 1 : 0;
            }
        }

        vector<int> selected(N + 1, 0);
        int n = N;
        int w = W;

        while (n > 0) {
            if (sol[n][w] != 0) {
                selected[n] = 1;
                w -= wt[n];
            } else {
                selected[n] = 0;
            }
            n--;
        }

        cout << "\nItems with weight ";
        for (int i = 1; i <= N; i++) {
            if (selected[i] == 1) {
                cout << val[i] << " ";
            }
        }
        cout << "are selected by the knapsack algorithm." << endl;
    }
};

int main() {
    ZeroOneKnapsack ks;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> wt(n + 1);
    vector<int> val(n + 1);

    cout << "Enter weight for " << n << " elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    cout << "Enter value for " << n << " elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    cout << "Enter knapsack weight: ";
    int W;
    cin >> W;

    ks.solve(wt, val, W, n);

    return 0;
}
