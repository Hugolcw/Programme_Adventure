#include <iostream>
#include <string>
using namespace std;
int main()
{
    int v, n;
    cin >> v >> n;

    string n_ary_result = "";

    if (v == 0)
    {
        n_ary_result == "0";
    }

    while (v > 0)
    {
        int remainder = v % n;
        n_ary_result = (char)('0' + remainder) + n_ary_result;
        v = v / n;
    }
    cout << n_ary_result;
    return 0;
}