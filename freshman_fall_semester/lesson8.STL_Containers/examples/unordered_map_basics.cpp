#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    map<string, int> ordered_map;

    unordered_map<string, int> unordered_map;

    cout << "--- Inserting elements ---" << endl;

    ordered_map["banana"] = 2;
    unordered_map["banana"] = 2;

    ordered_map["apple"] = 1;
    unordered_map["apple"] = 1;

    ordered_map["orange"] = 3;
    unordered_map["orange"] = 3;

    ordered_map["mango"] = 4;
    unordered_map["mango"] = 4;

    ordered_map["pear"] = 5;
    unordered_map["pear"] = 5;

    cout << "\n--- Traversing std::map (Sorted by Key) ---" << endl;
    for (const auto &pair : ordered_map)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\n--- Traversing std::unordered_map (Unordered) ---" << endl;
    for (const auto &pair : unordered_map)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\n--- Usage is identical ---" << endl;
    cout << "Apple's value: " << unordered_map["apple"] << endl;
    unordered_map["apple"] = 100;
    cout << "New apple's value: " << unordered_map["apple"] << endl;

    return 0;
}