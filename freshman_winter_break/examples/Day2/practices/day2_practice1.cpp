#include <iostream>

int main() {
    std::cout << "=== Practice 1: Number Classifier ===" << std::endl;
    
    // TODO: Implement the following tasks
    
    // Task 1: Check if a number is positive, negative, or zero
    std::cout << "\n--- Task 1: Positive/Negative/Zero ---" << std::endl;
    int number = -5;
    
    // Your code here: Use if-else to check and print result
    if (number > 0) {
        std::cout << "The number is positive" << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative" << std::endl; 
    } else if (number == 0) {
        std::cout << "The number is zero" << std::endl;
    }
    
    // Task 2: Check if a number is even or odd
    std::cout << "\n--- Task 2: Even or Odd ---" << std::endl;
    int num = 7;
    
    // Your code here: Use if-else and modulo operator (%)
    if (num % 2 != 0) {
        std::cout << "The number is odd" << std::endl;
    } else if (num % 2 == 0) {
        std::cout << "The number is even" << std::endl;
    }
    
    // Task 3: Find the largest of three numbers
    std::cout << "\n--- Task 3: Largest of Three ---" << std::endl;
    int a = 15, b = 23, c = 19;
    
    // Your code here: Use if-else to find and print the largest
    if (a > b && a > c) {
        std::cout << "Largest: " << a << std::endl;
    } else if (b > a && b > c) {
        std::cout << "Largest: " << b << std::endl;
    } else {
        std::cout << "Largest: " << c << std::endl;
    }
    
    // Task 4: Grade calculator
    std::cout << "\n--- Task 4: Grade Calculator ---" << std::endl;
    int score = 85;
    
    // Your code here: 
    // 90-100: A
    // 80-89: B
    // 70-79: C
    // 60-69: D
    // Below 60: F
    if (score >= 90 && score <= 100) {
        std::cout << "Grade: A" << std::endl;
    } else if (score < 90 && score >= 80) {
        std::cout << "Grade: B" << std::endl;
    } else if (score < 80 && score >= 70) {
        std::cout << "Grade: C" << std::endl;
    } else if (score < 70 && score >= 60) {
        std::cout << "Grade: D" << std::endl;
    } else if (score >= 0 && score < 60) {
        std::cout << "Grade: F" << std::endl;
    } else {
        std::cout << "Invalid score" << std::endl;
    }
    
    // Task 5: Simple menu using switch
    std::cout << "\n--- Task 5: Menu Selection ---" << std::endl;
    int choice = 2;
    
    // Your code here: Use switch statement
    // 1: Print "New Game"
    // 2: Print "Load Game"
    // 3: Print "Settings"
    // 4: Print "Exit"
    // default: Print "Invalid choice"
    switch(choice) {
        case 1:
            std::cout << "New Game" << std::endl;
            break;
        case 2:
            std::cout << "Load Game" << std::endl;
            break;
        case 3:
            std::cout << "Settings" << std::endl;
            break;
        case 4:
            std::cout << "Exit" << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
    
    return 0;
}