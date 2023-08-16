class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs) // my solution
    {
        string prefix = "";
        if (strs.size() == 1)
            return strs[0];
        for (int i = 0; i < strs.size() - 1; i++)
        {
            string current = prefix.empty() ? strs[i] : prefix; // first time prefix is empty, so we take the first string and then onwards we take the prefix
            string next = strs[i + 1];
            int j = 0;
            prefix = "";
            while (j < current.size() && j < next.size())
            {
                if (current[j] == next[j])
                {
                    prefix += current[j];
                    j++;
                }
                else
                {
                    break;
                }
            }
            if (j == 0) // no common prefix if the first character itself is not matching
                return prefix;
        }
        return prefix;
    }

    string longestCommonPrefix(vector<string> &str) // loved this solution
    {
        sort(str.begin(), str.end());             // sorting the array
        string ans = "";                          // creating a new empty string to store the common prefixes
        for (int i = 0; i < str[0].length(); i++) // max iterations = length of the first string
        {
            if (str[0][i] != str[str.size() - 1][i]) // checking the characters of the first and last string
                break;
            ans += str[0][i]; // concatinate if the characters are matching
        }
        return ans;
    }
    // NOTE: When you sort an array, it is enough to check for the common characters of the the first & last string of the sorted vector.
};