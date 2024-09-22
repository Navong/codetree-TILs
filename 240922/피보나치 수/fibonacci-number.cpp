#include <iostream>
using namespace std;

class Solution {
public:
    int fibonacci(int n, int * fib) {
        if (n <= 1)
            return n;
        
        // If this value is already computed, just return the value from memory.
        if (fib[n] != -1)
            return fib[n];
        
        // Otherwise, calculate it and store in memory
        else {
            fib[n] = fibonacci(n-1, fib) + fibonacci(n-2, fib);
            
            // Don't forget to handle recursion by setting the computed value in the array.
            return fib[n];
        }
    }

    void printFibonacci(int n) {
        int *fib = new int[n+1];

        for (int i = 0; i <= n; ++i)
            fib[i] = -1;

            cout << fibonacci(n, fib) << endl;
        
        delete[] fib;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    
    solution.printFibonacci(n);

    return 0;
}