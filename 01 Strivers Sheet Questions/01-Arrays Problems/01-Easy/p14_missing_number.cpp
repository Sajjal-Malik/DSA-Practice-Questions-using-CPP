#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the missing number in an array containing elements from 1 to N.
 */
int getMissingNumber(vector<int> &nums, int rangeLimit)
{
    // Calculate the sum of the first N natural numbers using the arithmetic series formula
    long long expectedSum = (1LL * rangeLimit * (rangeLimit + 1)) / 2;

    // Calculate the actual sum of elements present in the vector
    long long actualSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        actualSum += nums[i];
    }

    // The difference between the expected and actual sum reveals the missing value
    return (int)(expectedSum - actualSum);
}

int main()
{
    vector<int> numbers = {1, 2, 4, 5};
    int rangeLimit = 5;

    int missingValue = getMissingNumber(numbers, rangeLimit);

    cout << "Missing Number: " << missingValue << endl;

    return 0;
}
