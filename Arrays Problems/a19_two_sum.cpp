#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Approach 1: Brute Force
 * Time Complexity: O(n^2) - Iterates through every possible pair.
 * Space Complexity: O(1) - No extra space used.
 */
vector<int> twoSumBruteForce(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {}; // No solution found
}

/**
 * Approach 2: Two-Pass Hash Map
 * Time Complexity: O(n) - Two separate linear traversals.
 * Space Complexity: O(n) - Stores all elements in the map.
 */
vector<int> twoSumTwoPassHash(vector<int> &nums, int target)
{
    unordered_map<int, int> valToIndexMap;

    // First pass: Populate the map with all values and their indices
    for (int i = 0; i < nums.size(); i++)
    {
        valToIndexMap[nums[i]] = i;
    }

    // Second pass: Check if the complement exists in the map
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        // Ensure we don't use the same element twice (indices[diff] != i)
        if (valToIndexMap.count(complement) && valToIndexMap[complement] != i)
        {
            return {i, valToIndexMap[complement]};
        }
    }
    return {};
}

/**
 * Approach 3: One-Pass Hash Map (Optimized)
 * Time Complexity: O(n) - Single traversal.
 * Space Complexity: O(n) - Stores elements in the map as we go.
 */
vector<int> twoSumOnePassHash(vector<int> &nums, int target)
{
    unordered_map<int, int> visitedNumsMap; // key: value, value: index

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        // Search if the complement was already seen in a previous iteration
        if (visitedNumsMap.find(complement) != visitedNumsMap.end())
        {
            return {visitedNumsMap[complement], i};
        }

        // Store current number and its index for future lookups
        visitedNumsMap[nums[i]] = i;
    }
    return {};
}

void printResult(string method, vector<int> result)
{
    cout << method << ": ";
    if (!result.empty())
    {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << "Target: " << target << "\n"
         << endl;

    // Testing all three approaches
    printResult("Brute Force", twoSumBruteForce(nums, target));
    printResult("Two-Pass Hash", twoSumTwoPassHash(nums, target));
    printResult("One-Pass Hash", twoSumOnePassHash(nums, target));

    return 0;
}
