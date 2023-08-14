#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        string newString;
        for (char c : s)
        {
            if (isalnum(c))
            {
                newString += tolower(c);
            }
        }

        int start = 0;
        int end = newString.length()- 1;

        while (start < end)
        {
            if (newString[start] != newString[end])
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};