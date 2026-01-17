#include <bits/stdc++.h>
using namespace std;

// Accepts a standard C-style array and its size; uses a single-pass linear approach
int secondLargestElementBruteForce(int array[], int n)
{
    if (n < 2)
    {
        return -1;
    }
    // Initialize variables to track the smallest and second smallest elements
    int min = INT_MAX;
    int secondMin = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // Updates secondMax to the old max, then assigns the new highest value found
        if (array[i] < min)
        {
            // first set secondMax to Max and then update the max to new value
            secondMin = min;
            min = array[i];
        }
        // If the current element isn't the absolute max but is better than our current runner-up
        if (array[i] != min && array[i] < secondMin)
            secondMin = array[i];
    }
    return secondMin;
}

// Function to find the second smallest element in the array using two passes
int secondSmallestElement(int arr[], int n)
{
    // Edge case: when the array has less than 2 elements
    if (n < 2)
        return -1;

    // Initialize variables to track the smallest and second smallest elements
    int small = INT_MAX, second_small = INT_MAX;
    int i;

    // Find the absolute smallest element in the array
    for (i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
    }

    // Find the second smallest element
    for (i = 0; i < n; i++)
    {
        // If the current element is smaller than second_small and not equal to the smallest, update second_small
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
    }

    // If second_small remains INT_MAX, it means all elements were the same
    return (second_small == INT_MAX) ? -1 : second_small;
}

int main()
{

    int array[] = {2, 5, 1, 3, 0};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Brute Force Second Min: " << secondLargestElementBruteForce(array, n) << endl;

    cout << "Brute Force II Second Min: " << secondSmallestElement(array, n) << endl;

    return 0;
}
