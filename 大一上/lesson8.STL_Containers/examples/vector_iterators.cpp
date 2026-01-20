#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // 1.
    cout << "--- Traversing with iterators (read-only) ---" << endl;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl
         << endl;

    // 2.
    cout << "--- Modifying with iterators ---" << endl;
    cout << "Multiplying each element by 2..." << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        *it = *it * 2;
    }

    // 3.
    cout << "--- Verfying results with range-based for ---" << endl;
    for (int val : v)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}