#include <iostream>
#include <string>
using namespace std;

void swap(string *p1, string *p2) {
    string temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortThree(string *p1, string *p2, string *p3) {
    if (*p1 > *p2) swap(p1, p2);
    if (*p1 > *p3) swap(p1, p3);
    if (*p2 > *p3) swap(p2, p3);
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    sortThree(&s1, &s2, &s3);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}