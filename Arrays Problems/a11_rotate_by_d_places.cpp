#include <bits/stdc++.h>
using namespace std;

/**
 * Performs a rotation on a dataset by a specified number of positions.
 * This version uses the "Temporary Buffer" method.
 */
void rotateArrayBruteForce(int dataValues[], int totalSize, int shiftAmount, string moveDirection)
{
    // Normalize shiftAmount to handle values larger than the array size
    shiftAmount %= totalSize;
    if (shiftAmount == 0)
        return;

    // Use a descriptive name for the temporary storage
    int tempBuffer[totalSize];

    if (moveDirection == "left")
    {
        // 1. Store first 'shiftAmount' elements in the buffer
        for (int i = 0; i < shiftAmount; i++)
        {
            tempBuffer[i] = dataValues[i];
        }

        // 2. Shift the remaining elements to the front
        for (int i = shiftAmount; i < totalSize; i++)
        {
            dataValues[i - shiftAmount] = dataValues[i];
        }

        // 3. Move the buffered elements to the end of the array
        for (int i = 0; i < shiftAmount; i++)
        {
            dataValues[totalSize - shiftAmount + i] = tempBuffer[i];
        }
    }
    else if (moveDirection == "right")
    {
        // 1. Store the last 'shiftAmount' elements in the buffer
        for (int i = 0; i < shiftAmount; i++)
        {
            tempBuffer[i] = dataValues[totalSize - shiftAmount + i];
        }

        // 2. Shift the remaining elements to the back
        // Start from the end to avoid overwriting values
        for (int i = totalSize - 1; i >= shiftAmount; i--)
        {
            dataValues[i] = dataValues[i - shiftAmount];
        }

        // 3. Move the buffered elements to the front of the array
        for (int i = 0; i < shiftAmount; i++)
        {
            dataValues[i] = tempBuffer[i];
        }
    }
}

/**
 * Rotates an array in-place using the Reversal Algorithm.
 * Space Complexity: O(1)
 * Time Complexity: O(N)
 */
void rotateArrayOptimal(vector<int> &numbers, int shiftCount, string direction)
{
    int n = numbers.size();
    if (n == 0)
        return;

    // Ensure shiftCount is within the bounds of array size
    shiftCount %= n;
    if (shiftCount == 0)
        return;

    if (direction == "left")
    {
        // To rotate left by K:
        // 1. Reverse the first K elements
        // 2. Reverse the remaining N-K elements
        // 3. Reverse the whole array
        reverse(numbers.begin(), numbers.begin() + shiftCount);
        reverse(numbers.begin() + shiftCount, numbers.end());
        reverse(numbers.begin(), numbers.end());
    }
    else if (direction == "right")
    {
        // To rotate right by K:
        // 1. Reverse the whole array
        // 2. Reverse the first K elements
        // 3. Reverse the remaining N-K elements
        reverse(numbers.begin(), numbers.end());
        reverse(numbers.begin(), numbers.begin() + shiftCount);
        reverse(numbers.begin() + shiftCount, numbers.end());
    }
}

int main()
{
    int dataset[] = {1, 2, 3, 4, 5};
    int itemCount = sizeof(dataset) / sizeof(dataset[0]);
    int positionsToMove = 2;
    string targetDirection = "right";

    rotateArrayBruteForce(dataset, itemCount, positionsToMove, targetDirection);

    // Print the final result
    for (int i = 0; i < itemCount; i++)
    {
        cout << dataset[i] << " ";
    }

    return 0;
}
