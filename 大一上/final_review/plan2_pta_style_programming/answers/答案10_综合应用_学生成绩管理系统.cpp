#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string name;
    int score1, score2, score3;
    int total;
    double avg;
};

int getGrade(double avg) {
    if (avg >= 90) return 0;  // A
    else if (avg >= 80) return 1;  // B
    else if (avg >= 70) return 2;  // C
    else if (avg >= 60) return 3;  // D
    else return 4;  // F
}

void bubbleSort(Student stu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (stu[j].total < stu[j + 1].total) {
                // 交换
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    Student stu[105];
    int gradeCount[5] = {0};  // A, B, C, D, F
    
    // 输入学生信息
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score1 >> stu[i].score2 >> stu[i].score3;
        stu[i].total = stu[i].score1 + stu[i].score2 + stu[i].score3;
        stu[i].avg = stu[i].total / 3.0;
        
        // 统计分数段
        int grade = getGrade(stu[i].avg);
        gradeCount[grade]++;
    }
    
    // 找出最高分
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (stu[i].total > stu[maxIndex].total) {
            maxIndex = i;
        }
    }
    
    // 输出最高分
    cout << fixed << setprecision(1);
    cout << "最高分: " << stu[maxIndex].name << " " 
         << stu[maxIndex].total << " " << stu[maxIndex].avg << endl;
    
    // 输出分数段统计
    cout << "A: " << gradeCount[0] 
         << " B: " << gradeCount[1] 
         << " C: " << gradeCount[2] 
         << " D: " << gradeCount[3] 
         << " F: " << gradeCount[4] << endl;
    
    // 排序
    bubbleSort(stu, n);
    
    // 输出所有学生信息
    for (int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].total << " " << stu[i].avg << endl;
    }
    
    return 0;
}

