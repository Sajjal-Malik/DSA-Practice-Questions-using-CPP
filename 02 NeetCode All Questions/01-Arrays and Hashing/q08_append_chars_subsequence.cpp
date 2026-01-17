#include <iostream>
#include <string>

/**
 * Returns the number of target characters not found as a subsequence in source.
 */
int getMinCharsToAppend(std::string source, std::string target)
{
    int sourceIndex = 0;
    int targetIndex = 0;
    int sourceLength = source.length();
    int targetLength = target.length();

    // Find the longest prefix of target that exists as a subsequence in source
    while (sourceIndex < sourceLength && targetIndex < targetLength)
    {
        if (source[sourceIndex] == target[targetIndex])
        {
            targetIndex++; // Match found; move to next target character
        }
        sourceIndex++; // Always advance through source
    }

    // Characters remaining in target must be appended
    return targetLength - targetIndex;
}

int main()
{
    std::string sourceStr = "coaching";
    std::string targetStr = "coding";

    int charactersNeeded = getMinCharsToAppend(sourceStr, targetStr);
    std::cout << "Characters to append: " << charactersNeeded << std::endl;

    return 0;
}
