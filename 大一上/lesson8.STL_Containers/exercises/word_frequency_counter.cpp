#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> word_count;
    string word;

    cout << "请输入单词（输入 “quit” 结束）：" << endl;

    while (cin >> word)
    {
        if (word == "quit")
        {
            break;
        }
        word_count[word]++;
    }

    cout << "\n--- 词频统计结果 ---" << endl;
    for (const auto &pair : word_count)
    {
        cout << "'" << pair.first << "': " << pair.second << " 次" << endl;
    }

    return 0;
}