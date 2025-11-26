#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double len_a = 150.0;
    double len_b = 200.0;

    double total_distance = len_a + len_b;

    double x, y;
    cin >> x >> y;

    double relative_speed = x + y;

    double time = total_distance / relative_speed;

    cout << fixed << setprecision(2) << time << " seconds." << endl;

    return 0;
}