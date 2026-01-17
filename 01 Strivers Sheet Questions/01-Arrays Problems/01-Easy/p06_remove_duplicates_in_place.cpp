#include <bits/stdc++.h>
using namespace std;

// Removes duplicates using unordered_set and returns count of unique elements
int removeInPlaceDuplicatesUsingHashSet(vector<int> &nums)
{
    // Unordered set to store elements we have already seen
    unordered_set<int> seen;

    // Index where the next unique element will be written
    int index = 0;

    // Loop over each element in the array
    for (int num : nums)
    {
        // If num is not in seen, it's unique
        if (seen.find(num) == seen.end())
        {
            // Add this num to the set of seen numbers
            seen.insert(num);

            // Overwrite nums[index] with this unique num
            nums[index] = num;

            // Move index forward
            index++;
        }
    }
    // Return count of unique elements
    return index;
}

// Removes duplicates from a sorted array in-place.
int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    // Tracks the index of the last confirmed unique element
    int writeIndex = 0;

    // Iterate through the array to find new unique elements
    for (int readIndex = 1; readIndex < nums.size(); readIndex++)
    {
        // Compare current element with the last known unique element
        if (nums[readIndex] != nums[writeIndex])
        {
            writeIndex++;
            nums[writeIndex] = nums[readIndex];
        }
    }

    // The count of unique elements is the last index + 1
    return writeIndex + 1;
}

int main()
{

    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4};

    // Execute the chosen logic (using Hash Set here as an example)
    int k = removeInPlaceDuplicatesUsingHashSet(nums);

    cout << "k = " << k << "\nArray after removing duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}