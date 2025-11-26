#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> scores;
    int current_scores;

    cout << "请输入学生分数，输入 -1 结束：" << endl;

    while (true)
    {
        cin >> current_scores;
        if (current_scores == -1)
        {
            break;
        }
        scores.push_back(current_scores);
    }

    if (scores.empty())
    {
        cout << "没有输入任何分数" << endl;
        return 0;
    }

    int sum = 0;
    for (int score : scores)
    {
        sum += score;
    }

    double average = static_cast<double>(sum) / scores.size();

    cout << "--- 统计结果 ---" << endl;
    cout << "学生总数：" << scores.size() << endl;
    cout << "总分数：" << sum << endl;
    cout << "平均分：" << average << endl;

    return 0;
}