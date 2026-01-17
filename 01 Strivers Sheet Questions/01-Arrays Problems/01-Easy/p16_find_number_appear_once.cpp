#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Brute Force
 * Logic: For every element, perform a linear scan to count its occurrences.
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 */
int findSingleNumberBruteForce(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int currentElement = nums[i];
        int occurrenceCount = 0;

        // Traverse the array to count how many times currentElement appears
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == currentElement)
                occurrenceCount++;
        }

        // The element that appears exactly once is our target
        if (occurrenceCount == 1)
            return currentElement;
    }

    return -1;
}

/**
 * Approach 2: Frequency Array (Hashing)
 * Logic: Map elements to their frequencies using an array index.
 * Time Complexity: O(N) + O(N) + O(MaxElement)
 * Space Complexity: O(MaxElement) - can be high if MaxElement is large.
 */
int findSingleNumberUsingHashArray(vector<int> &nums)
{
    int n = nums.size();

    // Determine the range for the hash array
    int maxElement = nums[0];
    for (int i = 0; i < n; i++)
    {
        maxElement = max(maxElement, nums[i]);
    }

    // Initialize frequency array with zeros
    vector<int> freqCounter(maxElement + 1, 0);

    // Store the frequency of each element
    for (int i = 0; i < n; i++)
    {
        freqCounter[nums[i]]++;
    }

    // Find the element with a frequency of one
    for (int i = 0; i < n; i++)
    {
        if (freqCounter[nums[i]] == 1)
            return nums[i];
    }

    return -1;
}

/**
 * Approach 3: Bit Manipulation (XOR)
 * Logic: XORing a number with itself results in 0 (A ^ A = 0).
 * XORing with 0 remains the same (A ^ 0 = A). All pairs cancel out.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int findSingleNumberUsingXOR(vector<int> &nums)
{
    int xorResult = 0;

    // XOR all elements; pairs will nullify each other
    for (int currentNum : nums)
    {
        xorResult ^= currentNum;
    }

    return xorResult;
}

int main()
{
    // Input: Array where every element appears twice except for one
    vector<int> nums = {4, 1, 2, 1, 2};

    // Executing the optimal XOR approach
    int singleElement = findSingleNumberUsingXOR(nums);

    cout << "The element that appears only once is: " << singleElement << endl;

    return 0;
}
