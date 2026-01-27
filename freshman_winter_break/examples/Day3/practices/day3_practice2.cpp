#include <iostream>

// === Practice 2: Recursion vs Iteration Comparison (递归与迭代对比实现) ===
// Implement same functions using both recursion and iteration

// TODO: Task 1 - Factorial (阶乘)
// Implement factorial using recursion: factorialRecursive(n)
// Implement factorial using iteration: factorialIterative(n)
// Example: factorial(5) = 5 * 4 * 3 * 2 * 1 = 120

// Your code here for factorial functions
int factorialRecursive(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorialRecursive(n - 1);  // Multiply n with result
}

int factorialIterative(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

// TODO: Task 2 - Fibonacci (斐波那契数列)
// Implement Fibonacci using recursion: fibonacciRecursive(n)
// Implement Fibonacci using iteration: fibonacciIterative(n)
// Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21...
// fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2)

// Your code here for fibonacci functions
int fibonacciRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// TODO: Task 3 - Sum of digits (数字各位之和)
// Implement sum of digits using recursion: sumDigitsRecursive(n)
// Implement sum of digits using iteration: sumDigitsIterative(n)
// Example: sumDigits(12345) = 1 + 2 + 3 + 4 + 5 = 15

// Your code here for sumDigits functions
int sumDigitsRecursive(int n) {
    if (n == 0) return 0;  // Base case
    return n % 10 + sumDigitsRecursive(n / 10);
}

int sumDigitsIterative(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

// TODO: Task 4 - Power (幂运算)
// Implement power using recursion: powerRecursive(base, exp)
// Implement power using iteration: powerIterative(base, exp)
// Example: power(2, 5) = 2^5 = 32

// Your code here for power functions
int powerRecursive(int base, int exp) {
    if (exp == 0) return 1;  // Base case
    return base * powerRecursive(base, exp - 1);
}

int powerIterative(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int main() {
    std::cout << "=== Practice 2: Recursion vs Iteration ===" << std::endl;
    
    // --- Test Task 1: Factorial ---
    std::cout << "\n--- Task 1: Factorial ---" << std::endl;
    std::cout << "factorialRecursive(5) = " << factorialRecursive(5) << std::endl;
    std::cout << "factorialIterative(5) = " << factorialIterative(5) << std::endl;
    
    // --- Test Task 2: Fibonacci ---
    std::cout << "\n--- Task 2: Fibonacci ---" << std::endl;
    std::cout << "fibonacciRecursive(7) = " << fibonacciRecursive(7) << std::endl;
    std::cout << "fibonacciIterative(7) = " << fibonacciIterative(7) << std::endl;
    
    // --- Test Task 3: Sum of Digits ---
    std::cout << "\n--- Task 3: Sum of Digits ---" << std::endl;
    std::cout << "sumDigitsRecursive(12345) = " << sumDigitsRecursive(12345) << std::endl;
    std::cout << "sumDigitsIterative(12345) = " << sumDigitsIterative(12345) << std::endl;
    
    // --- Test Task 4: Power ---
    std::cout << "\n--- Task 4: Power ---" << std::endl;
    std::cout << "powerRecursive(2, 5) = " << powerRecursive(2, 5) << std::endl;
    std::cout << "powerIterative(2, 5) = " << powerIterative(2, 5) << std::endl;
    
    return 0;
}
