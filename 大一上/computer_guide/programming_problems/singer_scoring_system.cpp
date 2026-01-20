#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int judges = 7;
    double score;
    double sum = 0.0;
    double max_score = -1e9;
    double min_score = 1e9;

    for (int i = 0; i < judges; ++i) {
        cin >> score;
        sum += score;
        if (score > max_score) max_score = score;
        if (score < min_score) min_score = score;
    }

    double final_score = (sum - max_score - min_score) / (judges - 2);

    cout << fixed << setprecision(2) << "score=" << final_score << endl;
    return 0;
}
