#include <iostream>
#include <string>

// === DEFAULT PARAMETERS BEST PRACTICES (默认参数最佳实践) ===

// Rule 1: Default parameters must be at the end
void createUser(std::string name, int age = 18, std::string city = "Unknown") {
    std::cout << "Name: " << name << ", Age: " << age << ", City: " << city << std::endl;
}

// Rule 2: Default parameters in declaration, not definition
void printBox(int width, int height = 5);  // Declaration with default

// Rule 3: Cannot skip middle parameters
void setColor(int r = 0, int g = 0, int b = 0) {
    std::cout << "RGB(" << r << ", " << g << ", " << b << ")" << std::endl;
}

// === OVERLOADING VS DEFAULT PARAMETERS ===
// Sometimes overloading is better than default parameters

// Using overloading (more flexible)
double calculateArea(double radius) {
    return 3.14159 * radius * radius;  // Circle
}

double calculateArea(double width, double height) {
    return width * height;  // Rectangle
}

// === DEFAULT PARAMETERS WITH OVERLOADING ===
void display(int value, std::string prefix = "Value: ") {
    std::cout << prefix << value << std::endl;
}

void display(double value, std::string prefix = "Value: ") {
    std::cout << prefix << value << std::endl;
}

int main() {
    std::cout << "=== Day 3: Default Parameters Best Practices ===" << std::endl;
    
    // --- Example 1: Using default parameters ---
    std::cout << "\n--- Example 1: Default Parameters ---" << std::endl;
    createUser("Alice");                    // Uses both defaults
    createUser("Bob", 25);                  // Uses city default
    createUser("Charlie", 30, "Beijing");   // No defaults
    
    // --- Example 2: All parameters have defaults ---
    std::cout << "\n--- Example 2: All Defaults ---" << std::endl;
    setColor();              // RGB(0, 0, 0) - black
    setColor(255);           // RGB(255, 0, 0) - red
    setColor(0, 255);        // RGB(0, 255, 0) - green
    setColor(0, 0, 255);     // RGB(0, 0, 255) - blue
    
    // --- Example 3: Overloading vs Default Parameters ---
    std::cout << "\n--- Example 3: Overloading for Different Shapes ---" << std::endl;
    std::cout << "Circle area (r=5): " << calculateArea(5.0) << std::endl;
    std::cout << "Rectangle area (4x6): " << calculateArea(4.0, 6.0) << std::endl;
    
    // --- Example 4: Overloading with default parameters ---
    std::cout << "\n--- Example 4: Combined Approach ---" << std::endl;
    display(42);                        // Uses default prefix
    display(42, "Number: ");            // Custom prefix
    display(3.14);                      // Overloaded for double
    display(3.14, "Pi = ");             // Overloaded with custom prefix
    
    // --- Example 5: printBox with default ---
    std::cout << "\n--- Example 5: Declaration Default ---" << std::endl;
    printBox(10);        // Uses default height=5
    printBox(10, 8);     // Custom height
    
    return 0;
}

// Definition of printBox (no default here, already in declaration)
void printBox(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
