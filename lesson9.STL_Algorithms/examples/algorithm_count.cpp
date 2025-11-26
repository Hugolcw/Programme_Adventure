#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 谓词：返回 bool（true 或 false）的简单函数，将它当作参数传递给另一个函数。
bool isOdd(int n)
{
    return (n % 2 != 0);
}

int main()
{
    vector<int> v = {10, 30, 20, 30, 40, 50, 15, 25};

    // 1. std::count
    // 统计 vector 中有多少个 30
    cout << "--- std::count ---" << endl;

    int value_to_count = 30;
    int count_30 = count(v.begin(), v.end(), value_to_count);

    cout << "值 " << value_to_count << " 出现了 " << count_30 << " 次。" << endl;
    cout << endl;

    // 2. std::count_if
    // 统计 vector 中有多少个“奇数
    cout << "--- std::count_if ---" << endl;

    // count_if(begin, end, predicate_function)
    // 把 isOdd 作为一个参数传入
    int odd_numbers = count_if(v.begin(), v.end(), isOdd);

    cout << "Vector 中有 " << odd_numbers << " 个奇数。" << endl;
    cout << endl;

    // 3. 统计有多少偶数
    auto isEven = [](int n)
    { return (n % 2 == 0); };

    int even_numbers = count_if(v.begin(), v.end(), isEven);
    cout << "Vector 中有 " << even_numbers << " 个偶数，" << endl;

    return 0;
}