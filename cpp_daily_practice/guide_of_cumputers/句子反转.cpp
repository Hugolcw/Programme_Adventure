#include <iostream>
#include <string>
#include <vector>
#include <sstream>   // For istringstream
#include <algorithm> // For reverse
#include <cctype>    // For isdigit, islower, isupper, toupper, tolower

// Use 'using namespace std;' if you prefer,
// but being explicit is also good practice.
using namespace std;

// This function transforms a single word based on the rules
string transform(string word)
{

    if (word.empty())
    {
        return word;
    }

    char first_char = word[0];

    // Rule 1: Check if it is a number
    if (isdigit(first_char))
    {
        // If number, reverse it
        reverse(word.begin(), word.end());
    }
    // Rule 2: Check if it is a lowercase word
    else if (islower(first_char))
    {
        // If lowercase, change all to uppercase

        // --- FIX IS HERE ---
        // Use 'size_t' instead of 'int' for the loop counter
        for (size_t i = 0; i < word.length(); i++)
        {
            word[i] = toupper(word[i]);
        }
    }
    // Rule 3: Check if it is an uppercase word
    else if (isupper(first_char))
    {
        // If uppercase, change all to lowercase

        // --- FIX IS HERE ---
        // Use 'size_t' instead of 'int'
        for (size_t i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
    }

    // Return the modified word
    return word;
}

// The main function must be 'int' and return 0
int main()
{
    string line;

    // Read the entire line, including spaces
    getline(cin, line);

    // Use a string stream to split the line by spaces
    istringstream iss(line);
    string word;

    // Store all words in a vector
    vector<string> words;
    while (iss >> word)
    {
        words.push_back(word);
    }

    // Loop backwards from the last word to the first
    // Note: We check if the vector is not empty to avoid errors
    if (!words.empty())
    {
        for (int i = words.size() - 1; i >= 0; i--)
        {

            // Transform the word at the current index
            string transformed_word = transform(words[i]);

            // Print the result
            cout << transformed_word;

            // Print a space *unless* it is the very last word (i == 0)
            if (i > 0)
            {
                cout << " ";
            }
        }
    }

    // Print a single newline at the end
    cout << endl;

    // Return 0 to indicate successful execution
    return 0;
}