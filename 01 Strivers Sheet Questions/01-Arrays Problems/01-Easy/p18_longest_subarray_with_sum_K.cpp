#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Brute Force
 * Logic: Checks every possible subarray by calculating the sum using three nested loops.
 * Time Complexity: O(N^3), Space Complexity: O(1)
 */
int getLongestSubarrayBruteForce(vector<int> &nums, int targetSum)
{
    int arraySize = nums.size();
    int maxLength = 0;

    for (int start = 0; start < arraySize; start++)
    {
        for (int end = start; end < arraySize; end++)
        {
            int currentSubarraySum = 0;
            // Explicitly iterate to calculate sum of nums[start...end]
            for (int k = start; k <= end; k++)
            {
                currentSubarraySum += nums[k];
            }

            if (currentSubarraySum == targetSum)
            {
                maxLength = max(maxLength, end - start + 1);
            }
        }
    }
    return maxLength;
}

/**
 * Approach 2: Better (Cumulative Sum)
 * Logic: Optimizes the brute force by calculating the sum on the fly.
 * Time Complexity: O(N^2), Space Complexity: O(1)
 */
int getLongestSubarrayBetter(vector<int> &nums, int targetSum)
{
    int arraySize = nums.size();
    int maxLength = 0;

    for (int start = 0; start < arraySize; start++)
    {
        int runningSum = 0;
        for (int end = start; end < arraySize; end++)
        {
            // Add current element to the sum of previous elements in this window
            runningSum += nums[end];

            if (runningSum == targetSum)
            {
                maxLength = max(maxLength, end - start + 1);
            }
        }
    }
    return maxLength;
}

/**
 * Approach 3: Optimal (Prefix Sum + Hashing)
 * Logic: Uses a map to store the first occurrence of prefix sums to find the required remainder.
 * Time Complexity: O(N log N) with map or O(N) with unordered_map, Space Complexity: O(N)
 */
int getLongestSubarrayOptimal(vector<int> &nums, int targetSum)
{
    int arraySize = nums.size();
    // Maps prefixSum -> first index where this sum was achieved
    map<long long, int> prefixSumTracker;
    long long currentPrefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < arraySize; i++)
    {
        currentPrefixSum += nums[i];

        // Case 1: The subarray from the very beginning sums to targetSum
        if (currentPrefixSum == targetSum)
        {
            maxLength = max(maxLength, i + 1);
        }

        // Case 2: Check if (currentPrefixSum - targetSum) exists in the tracker.
        // If it does, the elements between that index and 'i' sum to targetSum.
        long long neededRemainder = currentPrefixSum - targetSum;
        if (prefixSumTracker.find(neededRemainder) != prefixSumTracker.end())
        {
            int subarrayLength = i - prefixSumTracker[neededRemainder];
            maxLength = max(maxLength, subarrayLength);
        }

        // Only store the prefixSum if it hasn't been seen before to maintain the "earliest" index
        // This ensures we get the longest possible subarray when a match is found later.
        if (prefixSumTracker.find(currentPrefixSum) == prefixSumTracker.end())
        {
            prefixSumTracker[currentPrefixSum] = i;
        }
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {2, 3, 5, 1, 9};
    int targetSum = 10;

    cout << "Longest Subarray Length: " << getLongestSubarrayOptimal(nums, targetSum) << endl;

    return 0;
}
