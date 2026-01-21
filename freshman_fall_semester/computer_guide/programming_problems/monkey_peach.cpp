#include <iostream>
using namespace std;

int main() {
    
    int x;
    cin >> x;
    
    int n3;
    n3 = 2 * 100 / (100 - x);

    int n2;
    n2 = (n3 + 1) * 100 / (100 - x);
    
    int n1; 
    n1 = (n2 + 1) * 100 / (100 - x);

    cout << "The monkey taken " << n1 << " peaches at the first day." << endl;
    
    return 0;
}
