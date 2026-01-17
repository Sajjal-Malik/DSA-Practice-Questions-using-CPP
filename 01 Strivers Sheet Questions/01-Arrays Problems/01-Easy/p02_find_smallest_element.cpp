#include <bits/stdc++.h>
using namespace std;

// Sort Method: O(N log N) time complexity
int largestElementSortMethod(vector<int> &arr)
{
    // Rearrange elements in ascending order
    sort(arr.begin(), arr.end());

    // The smallest value is now at the first index
    return arr[0];
}

// Iterative Method: O(N) time complexity (More efficient)
int largestElementBruteForce(int array[], int n)
{
    // Initialize min with the largest possible integer
    int minimum = INT_MIN;

    // Traverse the array once to find the min value
    for (int i = 0; i < n; i++)
    {
        if (array[i] < minimum)
            minimum = array[i];
    }
    return minimum;
}

int main()
{
    int array[] = {2, 5, 1, 3, 0};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Brute Force Min: " << largestElementBruteForce(array, n) << endl;

    vector<int> arr = {2, 5, 1, 3, 0};
    cout << "Sort Method Min: " << largestElementSortMethod(arr) << endl;

    return 0;
}
