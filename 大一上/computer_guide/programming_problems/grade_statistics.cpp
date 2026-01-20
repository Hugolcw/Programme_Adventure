#include <iostream>
using namespace std;
int main() {
    int countA = 0;
    int countP = 0;
    int countF = 0;

    while(true) {
        int score;
        cin >> score;
        if (score < 0) {
            break;
        }
        else if (score >= 90) {
            countA++;
        }
        else if (score >= 60) {
            countP++;
        }
        else {
            countF++;
        }
    }
    cout << "A等级" << countA << "人" << endl;
    cout << "P等级" << countP << "人" << endl;
    cout << "F等级" << countF << "人" << endl;

    return 0;
}