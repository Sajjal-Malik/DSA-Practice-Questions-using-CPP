#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the length of the longest subarray that sums up to k.
 * Time Complexity: O(n^3) - Iterates through all possible subarrays and sums them.
 * Space Complexity: O(1)
 */
int longestSubarrayBruteForce(vector<int> &numbers, int targetSum)
{
    int totalElements = numbers.size();
    int maxSubarrayLength = 0;

    // Outer loop: Defines the starting index of the subarray
    for (int startIndex = 0; startIndex < totalElements; startIndex++)
    {
        // Middle loop: Defines the ending index of the subarray
        for (int endIndex = startIndex; endIndex < totalElements; endIndex++)
        {
            int currentSubarraySum = 0;

            // Inner loop: Calculates the sum of elements from startIndex to endIndex
            for (int k = startIndex; k <= endIndex; k++)
            {
                currentSubarraySum += numbers[k];
            }

            // Check if the current sum matches the target
            if (currentSubarraySum == targetSum)
                maxSubarrayLength = max(maxSubarrayLength, endIndex - startIndex + 1);
        }
    }

    return maxSubarrayLength;
}

/**
 * Finds the length of the longest subarray that sums up to k.
 * Optimized for positive integers using the Two-Pointer / Sliding Window approach.
 * Time Complexity: O(2n) ≈ O(n) - Each pointer moves at most n times.
 * Space Complexity: O(1)
 */
int longestSubarrayOptimal(vector<int> &numbers, int targetSum)
{
    int totalElements = numbers.size();
    int maxLen = 0;
    int leftPointer = 0, rightPointer = 0;
    int currentWindowSum = numbers[0];

    while (rightPointer < totalElements)
    {
        // If current sum exceeds target, shrink the window from the left
        while (leftPointer <= rightPointer && currentWindowSum > targetSum)
        {
            currentWindowSum -= numbers[leftPointer];
            leftPointer++;
        }

        // If current sum matches target, update the maximum length found
        if (currentWindowSum == targetSum)
        {
            maxLen = max(maxLen, rightPointer - leftPointer + 1);
        }

        // Move the right pointer forward to expand the window
        rightPointer++;

        // Add the next element to the sum if within bounds
        if (rightPointer < totalElements)
            currentWindowSum += numbers[rightPointer];
    }

    return maxLen;
}

int main()
{
    // Input array and target sum
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int target = 15;

    // Calculate result using the brute force approach
    int result = longestSubarrayBruteForce(arr, target);

    cout << "Longest Subarray Length: " << result << endl;

    return 0;
}
