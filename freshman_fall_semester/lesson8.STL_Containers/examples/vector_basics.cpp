#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_scores(const vector<int> &scores)
{
    cout << "Vector contents (" << scores.size() << " elements): [";

    for (int score : scores)
    {
        cout << score << " ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> high_scores;

    cout << "--- Adding scores..." << endl;
    high_scores.push_back(95);
    high_scores.push_back(100);
    high_scores.push_back(87);

    print_scores(high_scores);
    cout << endl;

    cout << "--- Accessing elements..." << endl;
    cout << "The first score is: " << high_scores.at(0) << endl;

    cout << "The second score is: " << high_scores[1] << endl;
    cout << endl;

    cout << "--- Modifying an element..." << endl;
    high_scores.at(2) = 90;
    print_scores(high_scores);
    cout << endl;

    cout << "--- Other operation..." << endl;
    cout << "Is the vector empty? " << (high_scores.empty() ? "Yes" : "No") << endl;

    high_scores.pop_back();
    cout << "After .pop_back():" << endl;
    print_scores(high_scores);

    high_scores.clear();
    cout << "After .clear():" << endl;
    print_scores(high_scores);
    cout << "Is the vector empty now? " << (high_scores.empty() ? "Yes" : "No") << endl;

    return 0;
}