#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int deterministic_partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void deterministic_quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = deterministic_partition(arr, low, high);

        deterministic_quick_sort(arr, low, pi - 1);
        deterministic_quick_sort(arr, pi + 1, high);
    }
}

int randomized_partition(vector<int>& arr, int low, int high) {
    srand(time(0));
    int random_pivot_index = low + rand() % (high - low + 1);
    swap(arr[random_pivot_index], arr[high]);
    return deterministic_partition(arr, low, high);
}

void randomized_quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomized_partition(arr, low, high);

        randomized_quick_sort(arr, low, pi - 1);
        randomized_quick_sort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Sorted array using deterministic quicksort:" << endl;
    deterministic_quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {12, 11, 13, 5, 6, 7};  // Reset the array
    cout << "Sorted array using randomized quicksort:" << endl;
    randomized_quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
