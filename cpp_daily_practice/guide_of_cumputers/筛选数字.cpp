#include <iostream>

using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;

        int count = 0;
        int num = 0;

        while (count < k)
        {
            num++;
            if (num % 3 != 0 && num % 10 != 3)
            {
                count++;
            }
        }
        cout << num << endl;
    }
    return 0;
}