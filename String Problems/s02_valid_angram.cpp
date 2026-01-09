#include <bits/stdc++.h>
using namespace std;

/*
    Function: isAnagramUsingSorting
    --------------------------------
    Checks whether two strings are anagrams by:
    1. Sorting both strings
    2. Comparing the sorted results

    If both sorted strings are identical,
    then the original strings are anagrams.
*/
bool isAnagramUsingSorting(string firstString, string secondString)
{
    // If lengths differ, they can never be anagrams
    if (firstString.length() != secondString.length())
    {
        return false;
    }

    // Sort both strings character-wise
    sort(firstString.begin(), firstString.end());
    sort(secondString.begin(), secondString.end());

    // Compare sorted strings
    return firstString == secondString;
}

/*
    Function: isAnagramUsingHashMap
    --------------------------------
    Checks whether two strings are anagrams using hash maps.

    Logic:
    - Count frequency of each character in both strings
    - If both frequency maps are identical, strings are anagrams
*/
bool isAnagramUsingHashMap(string firstString, string secondString)
{
    // Length check (mandatory for anagram validation)
    if (firstString.length() != secondString.length())
    {
        return false;
    }

    // Hash maps to store character frequencies
    unordered_map<char, int> frequencyMapFirst;
    unordered_map<char, int> frequencyMapSecond;

    // Traverse both strings and update character counts
    for (int index = 0; index < firstString.length(); index++)
    {
        frequencyMapFirst[firstString[index]]++;
        frequencyMapSecond[secondString[index]]++;
    }

    // Compare both hash maps
    return frequencyMapFirst == frequencyMapSecond;
}

int main()
{
    // Input strings
    string firstString = "racecar";
    string secondString = "carrace";

    // Check if the strings are anagrams using Hash Map method
    bool isAnagram = isAnagramUsingHashMap(firstString, secondString);

    // Output result
    if (isAnagram)
        cout << "true";
    else
        cout << "false";

    return 0;
}
