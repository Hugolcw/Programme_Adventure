#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> scores;
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
    }
    
    // 1. 计算平均分
    double sum = accumulate(scores.begin(), scores.end(), 0);
    double avg = sum / n;
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
    
    // 2. 找出最高分和最低分
    int max_score = *max_element(scores.begin(), scores.end());
    int min_score = *min_element(scores.begin(), scores.end());
    cout << "Max: " << max_score << ", Min: " << min_score << endl;
    
    // 3. 统计及格人数（>=60）
    int pass_count = count_if(scores.begin(), scores.end(), 
                              [](int s) { return s >= 60; });
    cout << "Pass: " << pass_count << endl;
    
    // 4. 降序排序
    sort(scores.begin(), scores.end(), greater<int>());
    for (size_t i = 0; i < scores.size(); i++) {
        cout << scores[i];
        if (i < scores.size() - 1) cout << " ";
    }
    cout << endl;
    
    // 5. 查找成绩
    int target;
    cin >> target;
    auto it = find(scores.begin(), scores.end(), target);
    if (it != scores.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}

