#include <bits/stdc++.h>
using namespace std;

/**
 * Brute Force Approach:
 * For every element, scan all elements to its right to find the maximum.
 * Time Complexity: O(N^2)
 * Space Complexity: O(N) for the result vector
 */
vector<int> getRightSideMaxBruteForce(const vector<int> &input_array)
{
    int size = input_array.size();
    vector<int> result(size);

    for (int i = 0; i < size; ++i)
    {
        int current_max = -1; // Default for the last element or if no right elements exist

        // Inner loop checks every element to the right of index i
        for (int j = i + 1; j < size; ++j)
        {
            current_max = max(current_max, input_array[j]);
        }
        result[i] = current_max;
    }
    return result;
}

/**
 * Optimal Approach:
 * Iterate from right to left, keeping track of the maximum seen so far.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
vector<int> getRightSideMaxOptimal(const vector<int> &input_array)
{
    int size = input_array.size();
    vector<int> result(size);
    int max_so_far = -1; // The rightmost element always results in -1

    // Traverse the array backwards
    for (int i = size - 1; i >= 0; --i)
    {
        // 1. Assign the max found to the right of this index
        result[i] = max_so_far;

        // 2. Update max_so_far to include the current element for the next index to the left
        max_so_far = max(max_so_far, input_array[i]);
    }
    return result;
}

int main()
{
    vector<int> my_numbers = {2, 4, 5, 3, 1, 2};

    vector<int> processed_array = getRightSideMaxOptimal(my_numbers);

    cout << "Original Array: ";
    for (int val : my_numbers)
        cout << val << " ";

    cout << "\nProcessed Array (Right Max): ";
    for (int val : processed_array)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
