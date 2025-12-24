#include <bits/stdc++.h>
using namespace std;

// APPROACH 1: Brute Force (Nested Loops)
// Time: O(n^2) - Very slow for large arrays
// Space: O(1) - No extra memory used
bool containsDuplicate(vector<int> &nums)
{
    for (int currentIdx = 0; currentIdx < nums.size(); currentIdx++)
    {
        // Compare current element with every element after it
        for (int nextIdx = currentIdx + 1; nextIdx < nums.size(); nextIdx++)
        {
            if (nums[nextIdx] == nums[currentIdx])
                return true; // Match found
        }
    }
    return false; // Exhausted all pairs with no match
}

// APPROACH 2: Sorting
// Time: O(n log n) - Due to the sorting step
// Space: O(1) or O(log n) depending on sort implementation
bool containsDuplicateUsingSorting(vector<int> &nums)
{
    // Sort elements so that duplicates sit next to each other
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {
        // Check if the current element is the same as the previous one
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}

// APPROACH 3: Hash Set (Best for speed)
// Time: O(n) - We only traverse the array once
// Space: O(n) - We store elements in a set to remember them
bool containsDuplicateUsingUnorderedSet(vector<int> &nums)
{
    unordered_set<int> seen; // Hash table to store unique numbers
    for (int num : nums)
    {
        // If 'num' is already in the set, it's a duplicate
        if (seen.count(num))
        {
            return true;
        }
        // Otherwise, add it to the set and keep moving
        seen.insert(num);
    }
    return false;
}

int main()
{
    // Initialize a test vector
    vector<int> arr = {1, 2, 3, 4, 5, 1};

    // Execute the chosen logic (using Brute Force here as an example)
    bool duplicateExist = containsDuplicate(arr);

    // Output the result to the console
    if (duplicateExist)
        cout << "Array contains duplicate" << endl;
    else
        cout << "Array does not contain duplicate" << endl;

    return 0;
}
