#include <bits/stdc++.h>
using namespace std;

// Accepts a standard C-style array and its size; uses a single-pass linear approach
int secondLargestElementBruteForce(int array[], int n)
{
    if (n < 2)
    {
        return -1;
    }
    // Initialize variables to track the largest and second largest elements
    int max = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // Updates secondMax to the old max, then assigns the new highest value found
        if (array[i] > max)
        {
            // first set secondMax to Max and then update the max to new value
            secondMax = max;
            max = array[i];
        }
        // If the current element isn't the absolute max but is better than our current runner-up
        if (array[i] != max && array[i] > secondMax)
            secondMax = array[i];
    }
    return secondMax;
}

// Function to find the second smallest and second largest elements in the array
int secondLargestElement(int arr[], int n)
{
    // Edge case: when the array has less than 2 elements
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;

    // Initialize variables to track the largest and second largest elements
    int large = INT_MIN, second_large = INT_MIN;
    int i;

    // Find  largest elements in the array
    for (i = 0; i < n; i++)
    {
        large = max(large, arr[i]);
    }

    // Find the second largest elements
    for (i = 0; i < n; i++)
    {
        // If the current element is larger than second_large and not equal to the largest, update second_large
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    // If second_large remains INT_MIN, it means all elements were the same
    return (second_large == INT_MAX) ? -1 : second_large;
}

int main()
{
    int array[] = {2, 5, 1, 3, 0};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Brute Force Second Max: " << secondLargestElementBruteForce(array, n) << endl;

    cout << "Brute Force II Second Max: " << secondLargestElement(array, n) << endl;

    return 0;
}
