class Solution {
public:
    bool isAnagram(string s, string t) {

        // 1st Approach TC: O(n) and SC: O(n)
        int i;
        unordered_map<char,int> mp;

        for(i=0 ; i<s.length() ; i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]]++;
            }
            else
            {
                mp[s[i]] = 1;
            }
        }
        for(i=0 ; i<t.length() ; i++)
        {
            if(mp.find(t[i])!=mp.end())
            {
                mp[t[i]]--;
            }
            else
            {
                return false;
            }
        }
        for(auto it: mp)
        {
            if(it.second!=0)
                return false;
        }
        return true;

        // 2nd approach TC: O(nlogn) and SC: O(n)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // if(s==t)
        //     return true;
        // return false;
    }
};