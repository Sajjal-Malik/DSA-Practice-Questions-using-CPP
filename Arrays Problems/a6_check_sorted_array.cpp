#include <bits/stdc++.h>
using namespace std;

/**
 * Brute Force Approach
 * Time Complexity: O(N^2) - Compares every element with every element after it.
 * Space Complexity: O(1)
 */
bool isSortedBruteForce(int nums[], int size)
{
    for (int currentIdx = 0; currentIdx < size; currentIdx++)
    {
        for (int nextIdx = currentIdx + 1; nextIdx < size; nextIdx++)
        {
            // If any future element is smaller than the current one, it's unsorted
            if (nums[currentIdx] > nums[nextIdx])
                return false;
        }
    }
    return true;
}

/**
 * Optimal Approach
 * Time Complexity: O(N) - Single pass through the array.
 * Space Complexity: O(1)
 */
bool isSortedOptimal(int nums[], int size)
{
    for (int i = 1; i < size; i++)
    {
        // Comparing the current element against its immediate predecessor
        int previousElement = nums[i - 1];
        int currentElement = nums[i];

        if (previousElement > currentElement)
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    // Calculate number of elements: Total size / size of one element
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test Brute Force Method
    bool sortedByBruteForceMethod = isSortedBruteForce(arr, n);
    if (sortedByBruteForceMethod)
        cout << "Array is sorted (Brute Force)" << endl;
    else
        cout << "Array is not Sorted" << endl;

    // Test Optimal Method
    bool sortedWithOptimalApproach = isSortedOptimal(arr, n);
    if (sortedWithOptimalApproach)
        cout << "Array is sorted (Optimal)" << endl;
    else
        cout << "Array is not Sorted" << endl;

    return 0;
}
