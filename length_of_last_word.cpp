class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int size = s.size();
        int length = 0;
        int i = size - 1;
        int flag = 0;
        while (i >= 0)
        {
            if (s[i] != ' ')
            {
                flag = 1;
                length++;
            }
            else if (flag)
            {
                break;
            }
            i--;
        }
        return length;
    }
};