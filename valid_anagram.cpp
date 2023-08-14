class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        int count[256] = {0};
        for (char c : s)
        {
            count[c - 'a']++;
        }
        int i = 0;
        while (i < t.length())
        {
            count[t[i] - 'a']--;
            if (count[t[i] - 'a'] < 0)
            {
                return false;
            }

            i++;
        }

        return true;
    }
};