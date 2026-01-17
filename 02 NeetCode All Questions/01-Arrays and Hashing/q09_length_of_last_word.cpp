#include <bits/stdc++.h>
using namespace std;

/**
 * Calculates the length of the last word in a string by manually
 * traversing from the end of the string backwards.
 */
int getLengthOfLastWordManual(string input_text)
{
    int currentIndex = input_text.length() - 1;
    int wordLength = 0;

    // Phase 1: Skip any trailing whitespace at the end of the string
    while (currentIndex >= 0 && input_text[currentIndex] == ' ')
    {
        currentIndex--;
    }

    // Phase 2: Count characters until the next space or start of string is reached
    while (currentIndex >= 0 && input_text[currentIndex] != ' ')
    {
        wordLength++;
        currentIndex--;
    }

    return wordLength;
}

/**
 * Calculates the length of the last word using C++ Standard Library
 * string manipulation functions for cleaner, more expressive code.
 */
int getLengthOfLastWordSTL(string input_text)
{
    input_text.erase(input_text.find_last_not_of(' ') + 1);
    return input_text.substr(input_text.find_last_of(' ') + 1).length();
}

int main()
{
    std::string phrase1 = "luffy is still joyboy";
    std::string phrase2 = "   fly me   to   the moon  ";

    // Example Output
    std::cout << "Phrase 1 Last Word Length: " << getLengthOfLastWordManual(phrase1) << std::endl;
    std::cout << "Phrase 2 Last Word Length: " << getLengthOfLastWordSTL(phrase2) << std::endl;

    return 0;
}
