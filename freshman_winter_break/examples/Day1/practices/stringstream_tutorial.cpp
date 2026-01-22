#include <iostream>
#include <sstream>
#include <string>

void basic_stringstream_demo() {
    std::cout << "=== Basic stringstream Demo ===" << std::endl;
    
    // 1. Creating a stringstream
    std::stringstream ss;
    
    // 2. Writing to stringstream (like cout)
    ss << "Hello";
    ss << " ";
    ss << "World";
    ss << "!";
    
    // 3. Getting the string content
    std::string result = ss.str();
    std::cout << "Result: " << result << std::endl;  // "Hello World!"
}

void writing_different_types() {
    std::cout << "\n=== Writing Different Types ===" << std::endl;
    
    std::stringstream ss;
    
    // Write different types - they get converted to strings automatically
    ss << "Number: " << 42;
    ss << ", Decimal: " << 3.14;
    ss << ", Character: " << 'A';
    ss << ", Boolean: " << true;
    
    std::cout << "Mixed types: " << ss.str() << std::endl;
}

void reading_from_stringstream() {
    std::cout << "\n=== Reading from stringstream ===" << std::endl;
    
    // Create stringstream with initial content
    std::stringstream ss("42 3.14 Hello");
    
    // Read different types back
    int number;
    double decimal;
    std::string word;
    
    ss >> number;   // Reads "42" and converts to int
    ss >> decimal;  // Reads "3.14" and converts to double
    ss >> word;     // Reads "Hello" as string
    
    std::cout << "Read integer: " << number << std::endl;
    std::cout << "Read double: " << decimal << std::endl;
    std::cout << "Read string: " << word << std::endl;
}

void stringstream_as_converter() {
    std::cout << "\n=== stringstream as Type Converter ===" << std::endl;
    
    // Convert number to string
    std::stringstream ss1;
    ss1 << 12345;
    std::string number_as_string = ss1.str();
    std::cout << "Number as string: '" << number_as_string << "'" << std::endl;
    
    // Convert string to number
    std::stringstream ss2("98765");
    int string_as_number;
    ss2 >> string_as_number;
    std::cout << "String as number: " << string_as_number << std::endl;
}

void getline_with_stringstream() {
    std::cout << "\n=== Using getline with stringstream ===" << std::endl;
    
    // This is the key technique for CSV parsing!
    std::string csv_data = "apple,banana,cherry,date";
    std::stringstream ss(csv_data);
    std::string item;
    
    std::cout << "Parsing CSV: " << csv_data << std::endl;
    std::cout << "Items:" << std::endl;
    
    // getline with custom delimiter (comma)
    while (std::getline(ss, item, ',')) {
        std::cout << "  - '" << item << "'" << std::endl;
    }
}

void practical_csv_parsing_example() {
    std::cout << "\n=== Practical CSV Number Parsing ===" << std::endl;
    
    std::string numbers_csv = "10,20,30,40,50";
    std::stringstream ss(numbers_csv);
    std::string token;
    
    std::cout << "Parsing: " << numbers_csv << std::endl;
    std::cout << "Numbers found:" << std::endl;
    
    while (std::getline(ss, token, ',')) {
        // Convert each token to integer
        std::stringstream converter(token);
        int number;
        if (converter >> number) {  // Try to read as integer
            std::cout << "  - " << number << std::endl;
        } else {
            std::cout << "  - '" << token << "' (invalid number)" << std::endl;
        }
    }
}

void stringstream_building_formatted_output() {
    std::cout << "\n=== Building Formatted Output ===" << std::endl;
    
    std::stringstream ss;
    
    // Build a formatted string piece by piece
    ss << "Report: ";
    ss << "Total items = " << 5;
    ss << ", Average = " << 87.5;
    ss << ", Status = " << "PASS";
    
    std::string report = ss.str();
    std::cout << report << std::endl;
    
    // Building a list format
    std::stringstream list_ss;
    list_ss << "Items: [";
    
    int items[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        list_ss << items[i];
        if (i < 4) {  // Add comma except for last item
            list_ss << ", ";
        }
    }
    list_ss << "]";
    
    std::cout << list_ss.str() << std::endl;
}

void stringstream_reuse_and_clear() {
    std::cout << "\n=== Reusing stringstream ===" << std::endl;
    
    std::stringstream ss;
    
    // First use
    ss << "First content";
    std::cout << "First: " << ss.str() << std::endl;
    
    // Clear and reuse
    ss.str("");        // Clear the content
    ss.clear();        // Clear any error flags
    
    ss << "Second content";
    std::cout << "Second: " << ss.str() << std::endl;
    
    // Another way to reuse
    ss.str("");
    ss.clear();
    
    ss << "Third: " << 123 << " + " << 456 << " = " << (123 + 456);
    std::cout << "Third: " << ss.str() << std::endl;
}

int main() {
    basic_stringstream_demo();
    writing_different_types();
    reading_from_stringstream();
    stringstream_as_converter();
    getline_with_stringstream();
    practical_csv_parsing_example();
    stringstream_building_formatted_output();
    stringstream_reuse_and_clear();
    
    return 0;
}