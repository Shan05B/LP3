
#include <iostream>
using namespace std;

// Non-Recursive Method
void fibonacciIterative(int n) {
    int a = 0, b = 1, c;

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

// Recursive Method
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) +
           fibonacciRecursive(n - 2);
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "\nNon-Recursive Fibonacci: ";
    fibonacciIterative(n);

    cout << "\nRecursive Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }

    return 0;
}
