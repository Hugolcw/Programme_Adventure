#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // 1.创建一个 map
    // Key 是 string 类型
    // Value 是 int 类型
    map<string, int> student_scores;

    // 2.插入元素
    cout << "--- Inserting elements..." << endl;

    // A:使用 [] 运算符
    // 如果 Key 不存在，会创建新的 Key-Value 对
    student_scores["Alice"] = 92;
    student_scores["Bob"] = 85;

    // B：使用 .insert()
    student_scores.insert(make_pair("Charlie", 95));

    // C: C++11 风格的 .insert()
    student_scores.insert({"David", 78});

    // 3.历遍 map
    cout << "\n--- Traversing the map..." << endl;
    // 历遍 map 时得到的是一个 std::pair 对象
    // 范围 for 循环会自动解包
    // 注意：pair.first 是 Key，pair.second 是 Value
    for (const auto &pair : student_scores)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 4.访问和修改元素
    cout << "\n--- Accessing and modifying..." << endl;

    // 使用 [] 访问
    cout << "Updating Bob's score..." << endl;
    student_scores["Bob"] = 88; // 把 85 改成 88
    cout << "Bob's new score: " << student_scores["Bob"] << endl;

    // 5.查找元素
    cout << "\n--- Finding elements..." << endl;

    // 使用 .find() 来安全地检查一个 Key 是否存在
    string student_name = "Eve";
    if (student_scores.find(student_name) == student_scores.end())
    {
        // .find() 如果没找到，会返回一个指向 .end() 的迭代器
        cout << student_name << " is not in the map." << endl;
    }
    else
    {
        cout << student_name << "'s score is " << student_scores[student_name] << endl;
    }

    // 检查 Alice
    student_name = "Alice";
    if (student_scores.find(student_name) == student_scores.end())
    {
        cout << student_name << " is not in the map." << endl;
    }
    else
    {
        cout << student_name << "'s score is " << student_scores[student_name] << endl;
    }

    // 6.删除元素
    cout << "\n--- Erasing elements..." << endl;
    student_scores.erase("David");
    cout << "After erasing David:" << endl;
    for (const auto &pair : student_scores)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}