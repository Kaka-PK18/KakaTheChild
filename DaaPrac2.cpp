#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of Jobs: ";
    int n;
    cin >> n;

    string a[n];
    int b[n];
    int c[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the Job: ";
        cin >> a[i];
        cout << "Enter the Profit: ";
        cin >> b[i];
        cout << "Enter the Deadline: ";
        cin >> c[i];
    }

    cout << "--Arranged Order--" << endl;
    cout << "Jobs: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Profit: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "Deadline: ";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] < b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
                string temp1 = a[i];
                a[i] = a[j];
                a[j] = temp1;
            }
        }
    }

    cout << endl;
    cout << "--Sorted Order--" << endl;
    cout << "Jobs: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Profit: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "Deadline: ";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }

    cout << endl;
    int max = c[0];
    for (int i = 0; i < n; i++) {
        if (c[i] > max) {
            max = c[i];
        }
    }

    string x[max];
    int xx[max];
    int profit = 0;

    for (int i = 0; i < n; i++) {
        int pp = c[i];
        pp = pp - 1;
        if (x[pp].empty()) {
            x[pp] = a[i];
            profit += b[i];
        } else {
            while (pp != -1) {
                if (x[pp].empty()) {
                    x[pp] = a[i];
                    profit += b[i];
                    break;
                }
                pp = pp - 1;
            }
        }
    }

    for (int i = 0; i < max; i++) {
        cout << "-->" << x[i];
    }
    cout << endl;

    cout << "Profit Earned: " << profit << endl;

    return 0;
}
