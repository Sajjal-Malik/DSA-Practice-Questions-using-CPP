#include <bits/stdc++.h>
using namespace std;

void shiftLeftOrRightByDPlaces(int array[], int size, int steps, string direction)
{
    int temp[] = {};

    for (int i = 0; i < steps; i++)
    {
        temp[i] = array[i];
    }

    if (direction == "left")
    {
        for (int step = 0; step < steps; step++)
        {
            for (int currIndex = 0; currIndex < size - 1; currIndex++)
            {
                array[currIndex] = array[currIndex + 1];
            }
        }

        for (int i = 0; i < steps; i++)
        {
                }
    }
    else if (direction == "right")
    {
        for (int step = 0; step < steps; step++)
        {
            for (int currIndex = size - 1; currIndex > 0; currIndex++)
            {
                array[currIndex] = array[currIndex + 1];
            }
        }
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int steps = 2;
    string direction = "right";

    shiftLeftOrRightByDPlaces(arr, size, 2, direction);

    return 0;
}