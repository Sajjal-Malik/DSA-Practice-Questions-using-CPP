#include <bits/stdc++.h>
using namespace std;

/**
 * Brute Force Approach:
 * For every element, scan all elements to its left to find the maximum.
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 */
vector<int> getLeftSideMaxBruteForce(const vector<int> &input_array)
{
    int size = input_array.size();
    vector<int> result(size);

    for (int i = 0; i < size; ++i)
    {
        int current_max = -1; // Default for the first element or if no left elements exist

        // Inner loop checks every element to the left of index i
        for (int j = 0; j < i; ++j)
        {
            current_max = max(current_max, input_array[j]);
        }
        result[i] = current_max;
    }
    return result;
}

/**
 * Optimal Approach:
 * Iterate from left to right, keeping track of the maximum seen so far.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
vector<int> getLeftSideMaxOptimal(const vector<int> &input_array)
{
    int size = input_array.size();
    vector<int> result(size);
    int max_so_far = -1; // The leftmost element has no elements to its left

    // Traverse the array forwards
    for (int i = 0; i < size; ++i)
    {
        // 1. Assign the max found to the left of this index
        result[i] = max_so_far;

        // 2. Update max_so_far to include the current element for the next index to the right
        max_so_far = max(max_so_far, input_array[i]);
    }
    return result;
}

int main()
{
    vector<int> my_numbers = {2, 4, 5, 3, 1, 2};

    vector<int> processed_array = getLeftSideMaxOptimal(my_numbers);

    cout << "Original Array: ";
    for (int val : my_numbers)
        cout << val << " ";

    cout << "\nProcessed Array (Left Max): ";
    for (int val : processed_array)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
