#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

struct Student
{
    string name;
    int score;
};

void print_roster(const string &title, const vector<Student> roster)
{
    cout << title << endl;
    cout << "--------------------" << endl;
    for (const auto &student : roster)
    {
        cout << student.name << "\t: " << student.score << "分" << endl;
    }
    cout << endl;
}

bool compare_by_score_descending(const Student &a, const Student &b)
{
    return a.score > b.score;
}

int main()
{
    vector<Student> roster = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"David", 92},
        {"Eve", 88}};
    print_roster("原始名册", roster);

    cout << "--- 查找 Charlie ---" << endl;
    string name_to_find = "Charlie";

    auto it = find_if(roster.begin(), roster.end(), [=](const Student &s)
                      { return s.name == name_to_find; });

    if (it != roster.end())
    {
        cout << "找到了！ " << it->name << " 的分数是: " << it->score << endl
             << endl;
    }
    else
    {
        cout << "未找到 " << name_to_find << endl
             << endl;
    }

    cout << "--- 按分数降序排序 ---" << endl;

    sort(roster.begin(), roster.end(), compare_by_score_descending);

    print_roster("降序名册", roster);

    return 0;
}