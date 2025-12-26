#include <iostream>
#include <iomanip>
using namespace std;

class Person {
protected:
    int NO;
public:
    Person(int id) {
        NO = id;
    }
    
    virtual void display() = 0;
};

class Student : public Person {
    int scores[5];
public:
    Student(int id, int s[]) : Person(id) {
        for (int i = 0; i <= 4; i++) {
            scores[i] = s[i];
        }
    }

    void display() {
        int cnt = 0;
        int sum = 0;
        int valid_n = 0;
        
        for (int i = 0; i < 5; i++) {
            if (scores[i] == -1) {
                cnt++;
            }
            else {
                sum += scores[i];
                valid_n++;
            }
        }
        
        cout << NO << " " << cnt;
        if (valid_n > 0) {
            cout << " " << fixed << setprecision(1) << (double)sum / valid_n << endl; 
        } else {
            cout << endl;
        }
    }
};

class Teacher : public Person {
    int papers[3];
public:
    Teacher(int id, int p[]) : Person(id) {
        for (int i = 0; i < 3; i++) {
            papers[i] = p[i];
        }
    }

    void display() {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += papers[i];
        }
        cout << NO << " " << total << endl;
    }
};

int main() {
    Person *pp[10];
    int idx = 0;

    int type;
    int id;
    int temp_scores[5];
    int temp_papers[3];

    while(true) {
        cin >> type;
        
        if (type == 0) {
            break;
        }

        cin >> id;
        
        if (type == 1) {
            for (int i = 0; i < 5; i++) {
                cin >> temp_scores[i];
            }
            pp[idx] = new Student(id, temp_scores);
            idx++;
        }
        else if (type == 2) {
            for (int i = 0; i < 3; i++) {
                cin >> temp_papers[i];
            }
            pp[idx] = new Teacher(id, temp_papers);
            idx++;
        }
    }

    for (int i = 0; i < idx; i++) {
        pp[i]->display();
    }
    return 0;
}