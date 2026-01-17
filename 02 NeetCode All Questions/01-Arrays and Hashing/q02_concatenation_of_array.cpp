#include <bits/stdc++.h>
using namespace std;
/**
 * Standard approach: uses reserve() and push_back().
 * Good for readability and general use.
 */
vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> concatenatedResult;

    // Reserve memory upfront to avoid multiple reallocations
    concatenatedResult.reserve(nums.size() * 2);

    for (int i = 0; i < 2; i++)
    {
        for (int num : nums)
        {
            concatenatedResult.push_back(num);
        }
    }

    return concatenatedResult;
}

/**
 * Optimal approach: uses direct index assignment.
 * Faster because it avoids the overhead of push_back logic.
 */
vector<int> getConcatenationOptimal(vector<int> &nums)
{
    int n = nums.size();

    // Pre-size the vector to 2n immediately
    vector<int> concatenatedResult(2 * n);

    for (int i = 0; i < n; ++i)
    {
        // Simultaneously map to the first and second half of the new array
        concatenatedResult[i] = concatenatedResult[i + n] = nums[i];
    }

    return concatenatedResult;
}

/**
 * Helper function to print vectors to the console
 */
void printVector(const string &label, const vector<int> &vec)
{
    cout << label << ": [ ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> originalArray = {1, 4, 1, 2};
    printVector("Original Array", originalArray);

    vector<int> standardResult = getConcatenation(originalArray);
    printVector("Standard Method", standardResult);

    vector<int> optimalResult = getConcatenationOptimal(originalArray);
    printVector("Optimal Method ", optimalResult);

    return 0;
}
