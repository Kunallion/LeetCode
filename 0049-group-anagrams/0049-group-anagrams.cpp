class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i;
        unordered_map<string, vector<string>> mp;
        string s1;
        vector<vector<string>> ans;
        for(i=0 ; i<strs.size() ; i++)
        {
            s1 = strs[i];
            sort(s1.begin(), s1.end());
            mp[s1].push_back(strs[i]);
            s1.clear();
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};