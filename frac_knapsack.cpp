#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, j = 0, max_qty, n, m;
    float sum = 0, max;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter the weights of each item: ";
    for (i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter the values of each item: ";
    for (i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter the maximum volume of knapsack: ";
    cin >> max_qty;

    m = max_qty;
    while (m >= 0) {
        max = 0;
        for (i = 0; i < n; i++) {
            if (static_cast<float>(value[i]) / static_cast<float>(weight[i]) > max) {
                max = static_cast<float>(value[i]) / static_cast<float>(weight[i]);
                j = i;
            }
        }
        if (weight[j] > m) {
            cout << "Quantity of item number: " << (j + 1) << " added is " << m << endl;
            sum += m * max;
            m = -1;
        } else {
            cout << "Quantity of item number: " << (j + 1) << " added is " << weight[j] << endl;
            m -= weight[j];
            sum += static_cast<float>(value[j]);
            value[j] = 0;
        }
    }
    cout << "The total profit is " << sum << endl;

    return 0;
}
