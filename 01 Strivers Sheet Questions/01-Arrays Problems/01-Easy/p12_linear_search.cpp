#include <bits/stdc++.h>
using namespace std;

/**
 * Searches for a specific value within an array.
 */
int findElementIndex(int searchArray[], int arraySize, int targetValue)
{
    for (int currentIndex = 0; currentIndex < arraySize; currentIndex++)
    {
        if (searchArray[currentIndex] == targetValue)
        {
            return currentIndex;
        }
    }
    return -1;
}

int main()
{
    int numbers[] = {64, 25, 12, 22, 11};
    int target = 22;

    int totalElements = sizeof(numbers) / sizeof(numbers[0]);

    int foundIndex = findElementIndex(numbers, totalElements, target);

    if (foundIndex != -1)
    {
        cout << "Element found at index: " << foundIndex << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
