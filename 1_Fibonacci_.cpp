#include <iostream> 
using namespace std; 
 
int fibonacciIterative(int n, int &steps) { 
    steps = 0; 
    if (n == 0) { 
        steps++; 
        return 0; 
    } 
    if (n == 1) { 
        steps++; 
        return 1; 
    } 
    int a = 0, b = 1, c; 
    for (int i = 2; i <= n; i++) { 
        c = a + b; 
        a = b; 
        b = c; 
        steps++; // Count each iteration 
    } 
    return b; 
} 
 
int fibonacciRecursive(int n, int &steps) { 
    steps++; // Count each function call 
    if (n == 0) 
        return 0; 
    if (n == 1) 
        return 1; 
    return fibonacciRecursive(n - 1, steps) + fibonacciRecursive(n - 2, steps); 
} 
 
int main() { 
    int n, steps = 0; 
    cout << "Enter n: "; 
    cin >> n; 
    
    int res = fibonacciIterative(n, steps); 
    cout << "Fibonacci(" << n << ") = " << res << endl; 
    cout << "Step count (iterative): " << steps << endl; 
    
    int result = fibonacciRecursive(n, steps); 
    cout << "Fibonacci(" << n << ") = " << result << endl; 
    cout << "Step count (recursive): " << steps << endl; 
    return 0; 
} 