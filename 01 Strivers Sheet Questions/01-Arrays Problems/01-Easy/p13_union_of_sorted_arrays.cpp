#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Using std::set
 * Time Complexity: O((n+m) log(n+m))
 * Space Complexity: O(n+m) to store elements in the set.
 */
vector<int> getUnionUsingSet(int firstArray[], int secondArray[], int firstSize, int secondSize)
{
    // Sets automatically handle uniqueness and sorting
    set<int> uniqueElements;

    for (int i = 0; i < firstSize; i++)
    {
        uniqueElements.insert(firstArray[i]);
    }

    for (int i = 0; i < secondSize; i++)
    {
        uniqueElements.insert(secondArray[i]);
    }

    // Initialize vector directly using set iterators
    return vector<int>(uniqueElements.begin(), uniqueElements.end());
}

/**
 * Approach 2: Two-Pointer Method (Optimal)
 * Assumes input arrays are already sorted.
 * Time Complexity: O(n + m)
 * Space Complexity: O(1) extra space (excluding the result vector).
 */
vector<int> getUnionOptimal(int firstArray[], int secondArray[], int firstSize, int secondSize)
{
    int i = 0; // Pointer for firstArray
    int j = 0; // Pointer for secondArray
    vector<int> mergedUnion;

    while (i < firstSize && j < secondSize)
    {
        // Case 1: Element in firstArray is smaller
        if (firstArray[i] <= secondArray[j])
        {
            // Add to result only if it's the first element or not a duplicate of the last added
            if (mergedUnion.empty() || mergedUnion.back() != firstArray[i])
            {
                mergedUnion.push_back(firstArray[i]);
            }

            // If both are equal, move both pointers to avoid duplicates; else move i
            if (firstArray[i] == secondArray[j])
                j++;
            i++;
        }
        // Case 2: Element in secondArray is smaller
        else
        {
            if (mergedUnion.empty() || mergedUnion.back() != secondArray[j])
            {
                mergedUnion.push_back(secondArray[j]);
            }
            j++;
        }
    }

    // Exhaust remaining elements in firstArray
    while (i < firstSize)
    {
        if (mergedUnion.empty() || mergedUnion.back() != firstArray[i])
        {
            mergedUnion.push_back(firstArray[i]);
        }
        i++;
    }

    // Exhaust remaining elements in secondArray
    while (j < secondSize)
    {
        if (mergedUnion.empty() || mergedUnion.back() != secondArray[j])
        {
            mergedUnion.push_back(secondArray[j]);
        }
        j++;
    }

    return mergedUnion;
}

int main()
{
    int firstArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int secondArray[] = {2, 3, 4, 4, 5, 11, 12};
    int firstSize = 10;
    int secondSize = 7;

    vector<int> unionResult = getUnionOptimal(firstArray, secondArray, firstSize, secondSize);

    cout << "Union of arrays: ";
    for (int element : unionResult)
    {
        cout << element << " ";
    }

    return 0;
}
