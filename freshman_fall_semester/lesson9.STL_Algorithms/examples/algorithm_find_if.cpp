#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isOdd(int n)
{
    return (n % 2 != 0);
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 15, 25, 50};

    cout << "Vector: [ ";
    for (int val : v)
        cout << val << " ";
    cout << "]" << endl;

    // 1. Use std::find_if
    // We pass our "condition" function, isOdd, as the third argument.
    // The algorithm will call isOdd() on each element (10, 20, 30, 40, ...)
    // until isOdd() returns true for the first time.
    auto it = find_if(v.begin(), v.end(), isOdd);

    // 2. Check the result
    if (it != v.end())
    {
        cout << "\nFound the First Odd Number: " << *it << endl;
    }
    else
    {
        cout << "\nNo odd numbers were found." << endl;
    }

    // 3. Example with no match
    vector<int> evens = {2, 4, 6, 8};
    auto it2 = find_if(evens.begin(), evens.end(), isOdd);

    if (it2 != evens.end())
    {
        cout << "Found the first odd number: " << endl;
    }
    else
    {
        cout << "No odd numbers were found in the 'evens' vector. " << endl;
    }

    return 0;
}