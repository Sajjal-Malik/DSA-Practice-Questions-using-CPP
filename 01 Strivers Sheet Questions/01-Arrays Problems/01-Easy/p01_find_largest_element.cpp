#include <bits/stdc++.h>
using namespace std;

// Sort Method: O(N log N) time complexity
int largestElementSortMethod(vector<int> &arr)
{
    // Rearrange elements in ascending order
    sort(arr.begin(), arr.end());

    // The largest value is now at the last index
    return arr[arr.size() - 1];
}

// Iterative Method: O(N) time complexity (More efficient)
int largestElementBruteForce(int array[], int n)
{
    // Initialize max with the smallest possible integer
    int maximum = INT_MIN;

    // Traverse the array once to find the max value
    for (int i = 0; i < n; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }
    return maximum;
}

int main()
{
    int array[] = {2, 5, 1, 3, 0};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Brute Force Max: " << largestElementBruteForce(array, n) << endl;

    vector<int> arr = {2, 5, 1, 3, 0};
    cout << "Sort Method Max: " << largestElementSortMethod(arr) << endl;

    return 0;
}
