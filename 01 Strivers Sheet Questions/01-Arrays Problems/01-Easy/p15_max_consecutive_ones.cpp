#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the length of the longest subarray containing only 1s.
 */
int findMaxConsecutiveOnes(int binaryArray[], int length)
{
    int currentStreak = 0;
    int maxStreakFound = 0;

    for (int i = 0; i < length; i++)
    {
        if (binaryArray[i] == 1)
        {
            // Increment streak and update global maximum
            currentStreak++;
            maxStreakFound = max(maxStreakFound, currentStreak);
        }
        else
        {
            // Reset streak when a 0 is encountered
            currentStreak = 0;
        }
    }
    return maxStreakFound;
}

int main()
{
    int inputData[] = {1, 1, 0, 1, 1, 1};
    int dataSize = sizeof(inputData) / sizeof(inputData[0]);

    int result = findMaxConsecutiveOnes(inputData, dataSize);

    cout << "Longest sequence of ones: " << result << endl;

    return 0;
}
