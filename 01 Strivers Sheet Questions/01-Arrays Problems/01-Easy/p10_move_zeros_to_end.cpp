#include <bits/stdc++.h>
using namespace std;

/**
 * Moves all zeros to the end of the vector using an auxiliary vector.
 * Time Complexity: O(N) | Space Complexity: O(N)
 */
vector<int> moveZeroesWithAuxiliarySpace(vector<int> &inputArray)
{
    int totalElements = inputArray.size();
    vector<int> processedArray(totalElements, 0);
    int nonZeroPosition = 0;

    // Populate the auxiliary vector with non-zero elements sequentially
    for (int i = 0; i < totalElements; i++)
    {
        if (inputArray[i] != 0)
        {
            processedArray[nonZeroPosition] = inputArray[i];
            nonZeroPosition++;
        }
    }

    // Update the original array reference
    inputArray = processedArray;
    return inputArray;
}

/**
 * Moves all zeros to the end in-place using a two-pointer approach.
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void moveZeroesInPlace(vector<int> &nums)
{
    int size = nums.size();
    int firstZeroIndex = -1;

    // Locate the first occurrence of zero to establish the swap boundary
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 0)
        {
            firstZeroIndex = i;
            break;
        }
    }

    // If no zeros are present, the array is already processed
    if (firstZeroIndex == -1)
        return;

    // Iterate from the first zero and swap non-zero elements forward
    for (int currentIndex = firstZeroIndex + 1; currentIndex < size; currentIndex++)
    {
        if (nums[currentIndex] != 0)
        {
            swap(nums[currentIndex], nums[firstZeroIndex]);
            firstZeroIndex++;
        }
    }
}

/**
 * Rearranges elements by placing all non-zero values first,
 * followed by all zero values using an explicit count-and-fill method.
 */
void moveZeroesByCounting(std::vector<int> &numbers)
{
    int totalSize = numbers.size();
    std::vector<int> resultBuffer(totalSize);

    int nonZeroIndex = 0;
    int zeroCount = 0;

    // Step 1: Identify non-zero elements and count zeros
    for (int i = 0; i < totalSize; i++)
    {
        if (numbers[i] != 0)
        {
            resultBuffer[nonZeroIndex++] = numbers[i];
        }
        else
        {
            zeroCount++;
        }
    }

    // Step 2: Fill the remaining space with zeros
    // (Note: std::vector already defaults to 0, but this is explicit per your logic)
    for (int i = 0; i < zeroCount; i++)
    {
        resultBuffer[nonZeroIndex++] = 0;
    }

    // Step 3: Update original array
    numbers = resultBuffer;
}

int main()
{
    vector<int> data = {1, 0, 2, 3, 0, 4, 0, 1};

    // Example using the in-place method for better memory efficiency
    moveZeroesInPlace(data);

    cout << "Processed Array: ";
    for (int value : data)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
