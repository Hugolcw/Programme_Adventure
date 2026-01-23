#include <iostream>

int main() {
    std::cout << "=== Loop Statements ===" << std::endl;
    
    // 1. for loop - Basic counting
    std::cout << "\n--- Basic for loop ---" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Count: " << i << std::endl;
    }
    
    // 2. for loop - Counting backwards
    std::cout << "\n--- Counting backwards ---" << std::endl;
    for (int i = 5; i >= 1; --i) {
        std::cout << "Countdown: " << i << std::endl;
    }
    
    // 3. for loop - Skip by 2
    std::cout << "\n--- Skip by 2 ---" << std::endl;
    for (int i = 0; i <= 10; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // 4. while loop
    std::cout << "\n--- while loop ---" << std::endl;
    int count = 1;
    while (count <= 5) {
        std::cout << "While count: " << count << std::endl;
        count++;
    }
    
    // 5. do-while loop (executes at least once)
    std::cout << "\n--- do-while loop ---" << std::endl;
    int num = 1;
    do {
        std::cout << "Do-while num: " << num << std::endl;
        num++;
    } while (num <= 5);
    
    // 6. Difference between while and do-while
    std::cout << "\n--- while vs do-while ---" << std::endl;
    
    int x = 10;
    std::cout << "while loop (condition false from start):" << std::endl;
    while (x < 5) {
        std::cout << "This won't print" << std::endl;
        x++;
    }
    std::cout << "while loop didn't execute" << std::endl;
    
    int y = 10;
    std::cout << "do-while loop (condition false from start):" << std::endl;
    do {
        std::cout << "This prints once: y = " << y << std::endl;
        y++;
    } while (y < 5);
    
    // 7. Nested loops
    std::cout << "\n--- Nested loops ---" << std::endl;
    std::cout << "Multiplication table (3x3):" << std::endl;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            std::cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        std::cout << std::endl;
    }
    
    // 8. break statement
    std::cout << "\n--- break statement ---" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        if (i == 5) {
            std::cout << "Breaking at i = " << i << std::endl;
            break;  // Exit the loop immediately
        }
        std::cout << "i = " << i << std::endl;
    }
    
    // 9. continue statement
    std::cout << "\n--- continue statement ---" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        if (i == 3) {
            std::cout << "Skipping i = " << i << std::endl;
            continue;  // Skip rest of this iteration
        }
        std::cout << "Processing i = " << i << std::endl;
    }
    
    // 10. Practical example: Sum of numbers
    std::cout << "\n--- Sum of numbers 1 to 10 ---" << std::endl;
    int sum = 0;
    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }
    std::cout << "Sum = " << sum << std::endl;
    
    // 11. Practical example: Find first even number
    std::cout << "\n--- Find first even number ---" << std::endl;
    int numbers[] = {1, 3, 5, 8, 9, 11};
    int array_size = 6;
    
    for (int i = 0; i < array_size; ++i) {
        if (numbers[i] % 2 == 0) {
            std::cout << "First even number: " << numbers[i] << std::endl;
            break;
        }
    }
    
    // 12. Practical example: Print only odd numbers
    std::cout << "\n--- Print only odd numbers ---" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}