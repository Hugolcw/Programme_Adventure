#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    ~Date() {}

    void display() {
        cout << year << "-";
        cout << setw(2) << setfill('0') << month << "-";
        cout << setw(2) << setfill('0') <<day << endl;
    }
};

int main() {
    int year, mouth, day;
    cin >> year >> mouth >> day;
    Date date(year, mouth, day);
    date.display();
    return 0;
}