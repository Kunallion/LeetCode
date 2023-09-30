class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;

        string temp="";
        vector<string> arr;

        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i]!=' ')
                temp.push_back(s[i]);
            else
            {
                arr.push_back(temp);
                temp.clear();
            }
        }
        if(temp.length()>0)
            arr.push_back(temp);
        
        if(arr.size()!=pattern.length())
            return false;

        for(int i=0 ; i<pattern.length() ; i++)
        {
            for(auto it:mp)
            {
                if(it.second==arr[i] && it.first!=pattern[i])
                    return false;
            }
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=arr[i])
                    return false;
            }
            else
            {
                mp[pattern[i]] = arr[i];
            }
        }
        return true;
    }
};