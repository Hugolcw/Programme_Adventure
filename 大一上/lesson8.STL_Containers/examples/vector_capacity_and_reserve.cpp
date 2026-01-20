#include <iostream>
#include <vector>

using namespace std;

void print_stats(const vector<int> &vec)
{
    cout << " - Size: " << vec.size() << endl;
    cout << " - Capacity: " << vec.capacity() << endl;
    cout << "---------------" << endl;
}

int main()
{
    // 1.
    vector<int> v1;
    print_stats(v1);

    vector<int> v2(5);
    print_stats(v2);

    vector<int> v3(5, 100);
    print_stats(v3);

    vector<int> v4 = {1, 2, 3, 4, 5};
    print_stats(v4);

    // 2.
    cout << "\n--- Size vs Capacity ---" << endl;
    vector<int> vec;
    cout << "Initial state:" << endl;
    print_stats(vec);

    cout << "Pushing back 3 elements..." << endl;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    print_stats(vec);

    vec.push_back(4);
    vec.push_back(5);
    cout << "Pushing back 2 more elements (may trigger reallocation):" << endl;
    print_stats(vec);

    // 3.
    cout << "\n--- Performance with .reserve() ---" << endl;

    vector<int> vec_a;
    cout << "Building vector A (no reserve)..." << endl;
    for (int i = 0; i < 10; ++i)
    {
        vec_a.push_back(i);
        cout << "Added " << i << ": ";
        cout << "Size=" << vec_a.size() << ", Capacity=" << vec_a.capacity() << endl;
    }

    cout << "\nBuilding vector B (with reserve)..." << endl;
    vector<int> vec_b;
    vec_b.reserve(10);

    for (int i = 0; i < 10; ++i)
    {
        vec_b.push_back(i);
        cout << "Added " << i << ": ";
        cout << "Size= " << vec_b.size() << ", Capacity=" << vec_b.capacity() << endl;
    }

    return 0;
}