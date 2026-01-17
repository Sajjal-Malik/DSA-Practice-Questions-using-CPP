#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Approach 1: Using substr and stoi
int countSeniorsUsingStoi(const vector<string> &details)
{
    int seniorCount = 0;
    for (const string &record : details)
    {
        // Extract 2 characters starting at index 11 and convert to integer
        int age = stoi(record.substr(11, 2));
        if (age > 60)
        {
            seniorCount++;
        }
    }
    return seniorCount;
}

// Approach 2: Using direct character math
int countSeniorsUsingArithmetic(const vector<string> &details)
{
    int seniorCount = 0;
    for (const string &record : details)
    {
        // Convert character digits to their integer values
        int tensDigit = record[11] - '0';
        int onesDigit = record[12] - '0';

        int age = (tensDigit * 10) + onesDigit;
        if (age > 60)
        {
            seniorCount++;
        }
    }
    return seniorCount;
}

int main()
{
    vector<string> passengerData = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};

    int result1 = countSeniorsUsingStoi(passengerData);
    int result2 = countSeniorsUsingArithmetic(passengerData);

    cout << "Results using stoi: " << result1 << endl;
    cout << "Results using arithmetic: " << result2 << endl;

    return 0;
}
