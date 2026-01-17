#include <bits/stdc++.h>
using namespace std;

/**
 * Returns true if the kth row and kth column are identical for all k.
 */
bool isValidWordSquare(const vector<string> &words)
{
    int rowCount = words.size();

    for (int row = 0; row < rowCount; ++row)
    {
        int colCount = words[row].size();

        for (int col = 0; col < colCount; ++col)
        {
            // Boundary check: ensure the corresponding (col, row) position exists
            if (col >= rowCount || row >= words[col].size())
            {
                return false;
            }

            // Symmetry check: char at (row, col) must match (col, row)
            if (words[row][col] != words[col][row])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // Case 1: All rows and columns match
    vector<string> validSquare = {
        "abcd",
        "bnrt",
        "crmy",
        "dtye"};

    // Case 2: Symmetry fails (e.g., words[0][2] 'l' != words[2][0] 'r')
    vector<string> invalidSquare = {
        "ball",
        "area",
        "read",
        "lady"};

    cout << boolalpha; // Output true/false instead of 1/0
    cout << "Test Case 1 is valid: " << isValidWordSquare(validSquare) << endl;
    cout << "Test Case 2 is valid: " << isValidWordSquare(invalidSquare) << endl;

    return 0;
}
