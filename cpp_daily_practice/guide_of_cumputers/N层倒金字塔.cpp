#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }
        int num_of_ones = n - i;
        if (num_of_ones > 0)
        {
            cout << 1;
            for (int j = 1; j < num_of_ones; j++)
            {
                cout << " " << 1;
            }
        }
        cout << endl;
    }
    return 0;
}