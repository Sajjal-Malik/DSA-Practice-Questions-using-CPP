#include <iostream>
#include <string>
#include <cmath> // Required for abs()

using namespace std;

/**
 * Calculates the "score" of a string.
 * The score is defined as the sum of the absolute differences
 * between the ASCII values of adjacent characters.
 */
int calculateStringScore(string inputStr)
{
    int totalScore = 0;
    int n = inputStr.length();

    // Iterate through the string up to the second-to-last character
    for (int i = 0; i < n - 1; i++)
    {
        // Calculate absolute difference between current char and next char
        int asciiDifference = abs(inputStr[i] - inputStr[i + 1]);

        // Accumulate the difference into the total score
        totalScore += asciiDifference;
    }

    return totalScore;
}

int main()
{
    string testWord = "leetcode";

    // Compute the score using our function
    int finalScore = calculateStringScore(testWord);

    // Display the result
    cout << "The score of the string \"" << testWord << "\" is: " << finalScore << endl;

    return 0;
}
