#include <iostream>

int main() {
    std::cout << "=== if/else Statements ===" << std::endl;
    
    // 1. Simple if statement
    std::cout << "\n--- Simple if ---" << std::endl;
    int age = 20;
    
    if (age >= 18) {
        std::cout << "You are an adult" << std::endl;
    }
    
    // 2. if-else statement
    std::cout << "\n--- if-else ---" << std::endl;
    int score = 75;
    
    if (score >= 60) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }
    
    // 3. if-else if-else chain
    std::cout << "\n--- if-else if-else ---" << std::endl;
    int grade = 85;
    
    if (grade >= 90) {
        std::cout << "Grade: A" << std::endl;
    } else if (grade >= 80) {
        std::cout << "Grade: B" << std::endl;
    } else if (grade >= 70) {
        std::cout << "Grade: C" << std::endl;
    } else if (grade >= 60) {
        std::cout << "Grade: D" << std::endl;
    } else {
        std::cout << "Grade: F" << std::endl;
    }
    
    // 4. Nested if statements
    std::cout << "\n--- Nested if ---" << std::endl;
    bool has_ticket = true;
    int ticket_age = 15;
    
    if (has_ticket) {
        std::cout << "You have a ticket" << std::endl;
        
        if (ticket_age < 18) {
            std::cout << "Child ticket price: $5" << std::endl;
        } else {
            std::cout << "Adult ticket price: $10" << std::endl;
        }
    } else {
        std::cout << "Please buy a ticket first" << std::endl;
    }
    
    // 5. Logical operators with if
    std::cout << "\n--- Logical operators ---" << std::endl;
    int temperature = 25;
    bool is_sunny = true;
    
    // AND operator (&&)
    if (temperature > 20 && is_sunny) {
        std::cout << "Perfect weather for a picnic!" << std::endl;
    }
    
    // OR operator (||)
    if (temperature < 10 || temperature > 35) {
        std::cout << "Extreme temperature!" << std::endl;
    } else {
        std::cout << "Comfortable temperature" << std::endl;
    }
    
    // NOT operator (!)
    if (!is_sunny) {
        std::cout << "Bring an umbrella" << std::endl;
    } else {
        std::cout << "No umbrella needed" << std::endl;
    }
    
    // 6. Comparison operators
    std::cout << "\n--- Comparison operators ---" << std::endl;
    int a = 10;
    int b = 20;
    
    if (a == b) std::cout << "a equals b" << std::endl;
    if (a != b) std::cout << "a not equals b" << std::endl;
    if (a < b)  std::cout << "a less than b" << std::endl;
    if (a <= b) std::cout << "a less than or equal to b" << std::endl;
    if (a > b)  std::cout << "a greater than b" << std::endl;
    if (a >= b) std::cout << "a greater than or equal to b" << std::endl;
    
    return 0;
}