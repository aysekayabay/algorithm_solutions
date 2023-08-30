class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> answer;

        for(string str : strs){
            string x = str;
            sort(x.begin(), x.end());
            myMap[x].push_back(str);
        }

        for(auto x : myMap){
            answer.push_back(x.second);
        }

        return answer;

    }
};