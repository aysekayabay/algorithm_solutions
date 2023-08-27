class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int h = haystack.size();
        int n = needle.size();

        if (n == 0)
            return 0;

        map<char, int> badChar;

        for (int i = 0; i < n; i++)
        {
            badChar[needle[i]] = i;
        }

        int i = 0;
        while (i <= h - n)
        {
            int j = n - 1;

            while (j >= 0 && needle[j] == haystack[i + j])
            {
                j--;
            }

            if (j < 0)
            {
                return i;
            }
            else
            {
                i += max(1, j - badChar[haystack[i + j]]);
            }
        }
        return -1;
    }
};
