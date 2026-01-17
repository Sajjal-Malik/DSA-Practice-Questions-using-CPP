#include <bits/stdc++.h>
using namespace std;

/**
 * Helper function to check if string 'sub' is a subsequence of 'full' using recursion.
 * @return True if 'sub' is a subsequence of 'full', false otherwise.
 */
bool isSubsequenceRecursiveHelper(const string &sub, const string &full, int subIdx, int fullIdx)
{
    // Base Case: All characters in the subsequence have been matched
    if (subIdx == sub.size())
    {
        return true;
    }
    // Base Case: Full string exhausted without matching all characters of subsequence
    if (fullIdx == full.size())
    {
        return false;
    }

    // If characters match, move both pointers forward
    if (sub[subIdx] == full[fullIdx])
    {
        return isSubsequenceRecursiveHelper(sub, full, subIdx + 1, fullIdx + 1);
    }

    // If no match, move only the full string pointer forward
    return isSubsequenceRecursiveHelper(sub, full, subIdx, fullIdx + 1);
}

/**
 * Iterative approach to determine if 'sub' is a subsequence of 'full'.
 * Time Complexity: O(n) where n is the length of the full string.
 * Space Complexity: O(1).
 */
bool isSubsequenceIterative(const string &sub, const string &full)
{
    int subIdx = 0;
    int fullIdx = 0;

    while (subIdx < sub.length() && fullIdx < full.length())
    {
        if (sub[subIdx] == full[fullIdx])
        {
            subIdx++;
        }
        fullIdx++;
    }

    return subIdx == sub.length();
}

int main()
{
    const string targetSubsequence = "ace";
    const string sourceString = "abcde";

    // Standard iterative check
    if (isSubsequenceIterative(targetSubsequence, sourceString))
    {
        cout << "Result: '" << targetSubsequence << "' is a subsequence of '" << sourceString << "'" << endl;
    }
    else
    {
        cout << "Result: Not a subsequence" << endl;
    }

    return 0;
}
