#include <bits/stdc++.h>
using namespace std;

/**
 * Shifts the array elements to the left by one position in-place.
 * This is the optimal approach with O(1) auxiliary space.
 */
void leftShiftByOne(int array[], int size)
{
    // Save the head element to wrap it around later
    int temp = array[0];
    // Move all elements one step to the left
    for (int currIndex = 0; currIndex < size - 1; currIndex++)
    {
        array[currIndex] = array[currIndex + 1];
    }
    // Place the saved head element at the tail
    array[size - 1] = temp;
}

int main()
{

    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Performing Optimal Shift In-Place..." << endl;
    leftShiftByOne(numbers, length);

    cout << "Current State of Array: ";
    for (int value : numbers)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}