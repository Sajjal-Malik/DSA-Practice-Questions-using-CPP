#include <bits/stdc++.h>
using namespace std;

/**
 * Shifts the array elements to the right by one position in-place.
 * This is the optimal approach with O(1) auxiliary space.
 */
void rightShiftByOne(int array[], int size)
{
    // Save the tail element to wrap it around to the head later
    int temp = array[size - 1];

    // Move all elements one step to the right
    // We iterate backwards to avoid overwriting data
    for (int currIndex = size - 1; currIndex > 0; currIndex--)
    {
        array[currIndex] = array[currIndex - 1];
    }

    // Place the saved tail element at the head
    array[0] = temp;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Performing Optimal Right Shift In-Place..." << endl;
    rightShiftByOne(numbers, length);

    cout << "Current State of Array: ";
    for (int value : numbers)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
