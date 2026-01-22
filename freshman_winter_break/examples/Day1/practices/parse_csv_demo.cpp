#include <iostream>
#include <string>
#include <sstream>

void demonstrate_parsing_concept() {
    std::cout << "=== What is PARSING? (什么是解析?) ===" << std::endl;
    
    // Original data (raw string)
    std::string raw_data = "Alice,20,Engineer";
    std::cout << "Raw data (原始数据): " << raw_data << std::endl;
    
    // PARSING = Breaking it into meaningful parts
    std::cout << "\nPARSING (解析) - Breaking into parts:" << std::endl;
    std::stringstream ss(raw_data);
    std::string part;
    int part_number = 1;
    
    while (std::getline(ss, part, ',')) {
        std::cout << "Part " << part_number << " (部分" << part_number << "): '" << part << "'" << std::endl;
        part_number++;
    }
    
    std::cout << "\nResult: We PARSED the string into 3 meaningful parts!" << std::endl;
    std::cout << "结果: 我们将字符串解析成了3个有意义的部分!" << std::endl;
}

void demonstrate_csv_concept() {
    std::cout << "\n=== What is CSV? (什么是CSV?) ===" << std::endl;
    
    std::cout << "CSV = Comma-Separated Values (逗号分隔值)" << std::endl;
    std::cout << "It's a simple way to store data in text format" << std::endl;
    std::cout << "这是一种用文本格式存储数据的简单方法" << std::endl;
    
    // Example 1: Numbers
    std::cout << "\nExample 1 - Numbers CSV:" << std::endl;
    std::string numbers_csv = "10,20,30,40,50";
    std::cout << "CSV: " << numbers_csv << std::endl;
    std::cout << "Meaning: Five numbers separated by commas" << std::endl;
    std::cout << "含义: 五个用逗号分隔的数字" << std::endl;
    
    // Example 2: Student info
    std::cout << "\nExample 2 - Student Info CSV:" << std::endl;
    std::string student_csv = "张三,20,计算机科学";
    std::cout << "CSV: " << student_csv << std::endl;
    std::cout << "Meaning: Name, Age, Major" << std::endl;
    std::cout << "含义: 姓名, 年龄, 专业" << std::endl;
    
    // Example 3: Shopping list
    std::cout << "\nExample 3 - Shopping List CSV:" << std::endl;
    std::string shopping_csv = "苹果,香蕉,橙子,葡萄";
    std::cout << "CSV: " << shopping_csv << std::endl;
    std::cout << "Meaning: List of fruits to buy" << std::endl;
    std::cout << "含义: 要买的水果清单" << std::endl;
}

void demonstrate_parse_csv_together() {
    std::cout << "\n=== PARSING CSV (解析CSV) ===" << std::endl;
    
    std::string csv_data = "100,200,300,400";
    std::cout << "Original CSV: " << csv_data << std::endl;
    std::cout << "原始CSV: " << csv_data << std::endl;
    
    std::cout << "\nParsing process (解析过程):" << std::endl;
    std::stringstream ss(csv_data);
    std::string token;
    int count = 1;
    
    while (std::getline(ss, token, ',')) {
        std::cout << "Step " << count << " (步骤" << count << "): Found '" << token << "'" << std::endl;
        
        // Convert to number
        int number = std::stoi(token);
        std::cout << "  -> Converted to number: " << number << std::endl;
        std::cout << "  -> 转换为数字: " << number << std::endl;
        
        count++;
    }
    
    std::cout << "\nResult: Successfully parsed CSV into individual numbers!" << std::endl;
    std::cout << "结果: 成功将CSV解析为单个数字!" << std::endl;
}

void real_world_examples() {
    std::cout << "\n=== Real World Examples (现实世界的例子) ===" << std::endl;
    
    std::cout << "Where you see CSV files:" << std::endl;
    std::cout << "你在哪里会看到CSV文件:" << std::endl;
    
    std::cout << "1. Excel exports (Excel导出)" << std::endl;
    std::cout << "2. Database exports (数据库导出)" << std::endl;
    std::cout << "3. Configuration files (配置文件)" << std::endl;
    std::cout << "4. Data analysis (数据分析)" << std::endl;
    
    std::cout << "\nWhy parsing is important:" << std::endl;
    std::cout << "为什么解析很重要:" << std::endl;
    
    std::cout << "- Programs need to understand data structure" << std::endl;
    std::cout << "- 程序需要理解数据结构" << std::endl;
    std::cout << "- Convert text into usable information" << std::endl;
    std::cout << "- 将文本转换为可用信息" << std::endl;
}

int main() {
    demonstrate_parsing_concept();
    demonstrate_csv_concept();
    demonstrate_parse_csv_together();
    real_world_examples();
    
    return 0;
}