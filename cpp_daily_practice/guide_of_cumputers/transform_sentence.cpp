#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

string transform(string word)
{
    if (word.empty())
    {
        return word;
    }

    char frist_char = word[0];

    if (isdigit(frist_char))
    {
        reverse(word.begin(), word.end());
    }

    else if (islower(frist_char))
    {
        for (char &c : word)
        {
            c = toupper(c);
        }
    }

    else if (isupper(frist_char))
    {
        for (char &c : word)
        {
            c = tolower(c);
        }
    }

    return word;
}

int main()
{
    string line;
    getline(cin, line);

    istringstream iss(line);
    string word;

    vector<string> words;
    while (iss >> word)
    {
        words.push_back(word);
    }

    for (int i = words.size() - 1; i >= 0; i--)
    {
        string transformed_word = transform(words[i]);

        cout << transformed_word;

        if (i > 0)
        {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}