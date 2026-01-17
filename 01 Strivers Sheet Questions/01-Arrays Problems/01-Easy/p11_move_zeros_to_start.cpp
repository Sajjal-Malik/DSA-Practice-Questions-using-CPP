#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Auxiliary Space
 * Fills non-zero elements into a new vector starting from the back.
 * Time: O(N) | Space: O(N)
 */
vector<int> moveZeroesToStartWithAuxiliarySpace(vector<int> inputArray)
{
    int n = inputArray.size();
    vector<int> processedArray(n, 0); // Pre-fill with zeros
    int nonZeroPosition = n - 1;      // Start filling from the end

    // Scan backward and place non-zero elements at the available end positions
    for (int i = n - 1; i >= 0; i--)
    {
        if (inputArray[i] != 0)
        {
            processedArray[nonZeroPosition] = inputArray[i];
            nonZeroPosition--;
        }
    }
    return processedArray;
}

/**
 * Approach 2: In-Place (Two-Pointer)
 * Swaps non-zero elements toward the back, pushing zeros to the front.
 * Time: O(N) | Space: O(1)
 */
void moveZeroesToStartInPlace(vector<int> &nums)
{
    int size = nums.size();
    int lastZeroIndex = -1;

    // 1. Locate the first zero encountered from the right
    for (int i = size - 1; i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            lastZeroIndex = i;
            break;
        }
    }

    // No zeros found
    if (lastZeroIndex == -1)
        return;

    // 2. Iterate backward and swap non-zero elements to the right boundary
    for (int i = lastZeroIndex - 1; i >= 0; i--)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[lastZeroIndex]);
            lastZeroIndex--;
        }
    }
}

/**
 * Approach 3: Explicit Count-and-Fill
 * Identifies non-zero elements and manually fills the remaining front with zeros.
 * Time: O(N) | Space: O(N)
 */
void moveZeroesToStartByCounting(vector<int> &numbers)
{
    int n = numbers.size();
    vector<int> resultBuffer(n);
    int nonZeroIndex = n - 1;

    // Step 1: Collect non-zero elements at the back
    for (int i = n - 1; i >= 0; i--)
    {
        if (numbers[i] != 0)
        {
            resultBuffer[nonZeroIndex--] = numbers[i];
        }
    }

    // Step 2: Fill remaining front positions with zeros
    while (nonZeroIndex >= 0)
    {
        resultBuffer[nonZeroIndex--] = 0;
    }

    numbers = resultBuffer;
}

/**
 * Bonus: Standard Library (STL) One-Liner
 * Efficiently partitions the vector based on a condition while maintaining order.
 */
void moveZeroesToStartSTL(vector<int> &nums)
{
    stable_partition(nums.begin(), nums.end(), [](int n)
                     {
                         return n == 0; // Move elements that are zero to the front
                     });
}

void printArray(const string &msg, const vector<int> &arr)
{
    cout << msg << ": ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main()
{
    vector<int> original = {1, 0, 2, 3, 0, 4, 0, 1};

    // Test Auxiliary Space
    vector<int> res1 = moveZeroesToStartWithAuxiliarySpace(original);
    printArray("Auxiliary Space", res1);

    // Test In-Place
    vector<int> res2 = original;
    moveZeroesToStartInPlace(res2);
    printArray("In-Place (2-Pointer)", res2);

    // Test Counting
    vector<int> res3 = original;
    moveZeroesToStartByCounting(res3);
    printArray("Count-and-Fill", res3);

    // Test STL
    vector<int> res4 = original;
    moveZeroesToStartSTL(res4);
    printArray("STL stable_partition", res4);

    return 0;
}
