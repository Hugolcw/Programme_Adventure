#include <iostream>

int main() {
    std::cout << "=== Practice 2: Loop Exercises ===" << std::endl;
    
    // TODO: Implement the following tasks
    
    // Task 1: Print numbers 1 to 10
    std::cout << "\n--- Task 1: Print 1 to 10 ---" << std::endl;
    
    // Your code here: Use a for loop
    for (int i = 1; i <= 10; i++) {
        std::cout << "number: " << i << std::endl;
    }
    
    // Task 2: Print even numbers from 2 to 20
    std::cout << "\n--- Task 2: Even Numbers 2 to 20 ---" << std::endl;
    
    // Your code here: Use a for loop with i += 2
    for (int i = 2; i <= 20; i += 2) {
        std::cout << "Even number: " << i << std::endl;
    }
    
    // Task 3: Calculate sum of numbers 1 to 100
    std::cout << "\n--- Task 3: Sum of 1 to 100 ---" << std::endl;
    
    // Your code here: Use a for loop and accumulate sum
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    std::cout << sum << std::endl;
    
    // Task 4: Print multiplication table for 5
    std::cout << "\n--- Task 4: Multiplication Table for 5 ---" << std::endl;
    
    // Your code here: Use a for loop
    // Print: 5 x 1 = 5, 5 x 2 = 10, ... 5 x 10 = 50
    for (int i = 1; i <= 10; i++) {
        std::cout << "5 x " << i << " = " << i * 5 << std::endl;
    }
    
    // Task 5: Count down from 10 to 1
    std::cout << "\n--- Task 5: Countdown ---" << std::endl;
    
    // Your code here: Use a for loop counting backwards
    for (int i = 10; i >= 1; i--) {
        std::cout << "number: " << i << std::endl;
    }
    
    // Task 6: Find factorial of 5 (5! = 5 * 4 * 3 * 2 * 1)
    std::cout << "\n--- Task 6: Factorial of 5 ---" << std::endl;
    
    // Your code here: Use a for loop to calculate factorial
    int product = 1;
    for (int i = 1; i <= 5; i++) {
        product *= i;
    }
    std::cout << "5! = " << product << std::endl;
    
    // Task 7: Print only numbers divisible by 3 from 1 to 30
    std::cout << "\n--- Task 7: Divisible by 3 ---" << std::endl;
    
    // Your code here: Use for loop with if statement or continue
    for (int i = 1; i <= 30; i++) {
        if (i % 3 == 0) {
            std::cout << "The number divisible by 3: " << i << std::endl;
        }
    }
    
    return 0;
}