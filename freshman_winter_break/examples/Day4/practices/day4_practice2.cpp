#include <iostream>
#include <cstring>  // For strlen, strcpy, etc.

// === Practice 2: String Processing Functions (字符串处理函数) ===

// TODO: Task 1 - String Length
// Create a function that calculates string length WITHOUT using strlen()
// Use pointer arithmetic to traverse the string
// Parameters: const char* str
// Return: int (length of string)

// Your code here


// TODO: Task 2 - String Copy
// Create a function that copies one string to another WITHOUT using strcpy()
// Use pointers to copy character by character
// Parameters: char* dest, const char* src
// Return: void

// Your code here


// TODO: Task 3 - String Concatenation
// Create a function that concatenates two strings WITHOUT using strcat()
// Append src to the end of dest
// Parameters: char* dest, const char* src
// Return: void

// Your code here


// TODO: Task 4 - String Reverse
// Create a function that reverses a string in-place
// Use two pointers (start and end) approach
// Parameters: char* str
// Return: void

// Your code here


// TODO: Task 5 - Count Vowels
// Create a function that counts vowels (a, e, i, o, u) in a string
// Use pointer to traverse the string
// Parameters: const char* str
// Return: int (number of vowels)

// Your code here


int main() {
    std::cout << "=== Practice 2: String Processing Functions ===" << std::endl;
    
    // --- Test Task 1: String Length ---
    std::cout << "\n--- Task 1: String Length ---" << std::endl;
    // TODO: Test your string length function
    // const char* str1 = "Hello, World!";
    // std::cout << "Length of \"" << str1 << "\": " << myStrlen(str1) << std::endl;
    
    // --- Test Task 2: String Copy ---
    std::cout << "\n--- Task 2: String Copy ---" << std::endl;
    // TODO: Test your string copy function
    // char dest[50];
    // const char* src = "Copy this string";
    // myStrcpy(dest, src);
    // std::cout << "Copied string: " << dest << std::endl;
    
    // --- Test Task 3: String Concatenation ---
    std::cout << "\n--- Task 3: String Concatenation ---" << std::endl;
    // TODO: Test your string concatenation function
    // char str[100] = "Hello";
    // const char* append = " World!";
    // myStrcat(str, append);
    // std::cout << "Concatenated: " << str << std::endl;
    
    // --- Test Task 4: String Reverse ---
    std::cout << "\n--- Task 4: String Reverse ---" << std::endl;
    // TODO: Test your string reverse function
    // char str2[] = "Reverse";
    // std::cout << "Original: " << str2 << std::endl;
    // reverseString(str2);
    // std::cout << "Reversed: " << str2 << std::endl;
    
    // --- Test Task 5: Count Vowels ---
    std::cout << "\n--- Task 5: Count Vowels ---" << std::endl;
    // TODO: Test your count vowels function
    // const char* str3 = "Education";
    // std::cout << "Vowels in \"" << str3 << "\": " << countVowels(str3) << std::endl;
    
    return 0;
}
