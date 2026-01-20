#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    char target;
    cin >> target;

    int n;
    cin >> n;

    vector<string> valid_strings;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int count = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (tolower(s[j]) == tolower(target))
            {
                count++;
            }
        }

        if (count >= 2)
        {
            valid_strings.push_back(s);
        }
    }

    for (int i = valid_strings.size() - 1; i >= 0; i--)
    {
        cout << valid_strings[i] << endl;
    }

    return 0;
}