class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int i, ans=0, flag=0;
        
        for(i=0 ; i<s.length() ; i++)
            mp[s[i]]++;

        for(auto it:mp){
            ans += (it.second/2)*2;
            it.second %= 2;
            if(it.second==1 && flag==0)
            {
                flag=1;
                ans += 1;
            }
        }
        return ans;
    }
};