#include <iostream>

int main() {
    std::cout << "=== switch Statements ===" << std::endl;
    
    // 1. Basic switch statement
    std::cout << "\n--- Basic switch ---" << std::endl;
    int day = 3;
    
    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
            break;
    }
    
    // 2. switch with char
    std::cout << "\n--- switch with char ---" << std::endl;
    char grade = 'B';
    
    switch (grade) {
        case 'A':
            std::cout << "Excellent!" << std::endl;
            break;
        case 'B':
            std::cout << "Good!" << std::endl;
            break;
        case 'C':
            std::cout << "Fair" << std::endl;
            break;
        case 'D':
            std::cout << "Poor" << std::endl;
            break;
        case 'F':
            std::cout << "Fail" << std::endl;
            break;
        default:
            std::cout << "Invalid grade" << std::endl;
            break;
    }
    
    // 3. switch without break (fall-through)
    std::cout << "\n--- Fall-through example ---" << std::endl;
    int month = 2;
    
    switch (month) {
        case 12:
        case 1:
        case 2:
            std::cout << "Winter" << std::endl;
            break;
        case 3:
        case 4:
        case 5:
            std::cout << "Spring" << std::endl;
            break;
        case 6:
        case 7:
        case 8:
            std::cout << "Summer" << std::endl;
            break;
        case 9:
        case 10:
        case 11:
            std::cout << "Autumn" << std::endl;
            break;
        default:
            std::cout << "Invalid month" << std::endl;
            break;
    }
    
    // 4. Calculator using switch
    std::cout << "\n--- Simple Calculator ---" << std::endl;
    char operation = '+';
    double num1 = 10.0;
    double num2 = 5.0;
    double result;
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation" << std::endl;
            break;
    }
    
    // 5. Comparing switch vs if-else
    std::cout << "\n--- switch vs if-else ---" << std::endl;
    int choice = 2;
    
    // Using switch (cleaner for multiple exact values)
    std::cout << "Using switch: ";
    switch (choice) {
        case 1: std::cout << "Option 1" << std::endl; break;
        case 2: std::cout << "Option 2" << std::endl; break;
        case 3: std::cout << "Option 3" << std::endl; break;
        default: std::cout << "Invalid" << std::endl; break;
    }
    
    // Using if-else (same result, but more verbose)
    std::cout << "Using if-else: ";
    if (choice == 1) {
        std::cout << "Option 1" << std::endl;
    } else if (choice == 2) {
        std::cout << "Option 2" << std::endl;
    } else if (choice == 3) {
        std::cout << "Option 3" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
    
    return 0;
}