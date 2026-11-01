
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int count1 = 0, count2 = 0;

// Partition function
int partition(int a[], int low, int high, int &count) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        count++;

        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high, count1);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(int a[], int low, int high) {
    if (low < high) {

        int randomIndex = low + rand() % (high - low + 1);

        swap(a[randomIndex], a[high]);

        int p = partition(a, low, high, count2);

        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n, a[100], b[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    srand(time(0));

    quickSort(a, 0, n - 1);

    randomizedQuickSort(b, 0, n - 1);

    cout << "\nDeterministic Quick Sort:\n";
    display(a, n);
    cout << "Comparisons: " << count1 << endl;

    cout << "\nRandomized Quick Sort:\n";
    display(b, n);
    cout << "Comparisons: " << count2 << endl;

    return 0;
}
/*
Enter number of elements: 6
Enter array elements:
45 12 78 34 23 10

Deterministic Quick Sort:
10 12 23 34 45 78 
Comparisons: 11

Randomized Quick Sort:
10 12 23 34 45 78 
Comparisons: 12

*/