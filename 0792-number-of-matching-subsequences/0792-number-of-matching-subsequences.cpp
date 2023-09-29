// APPROACH 1 -> TLE
// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int i, j, k, ans=0;
//         for(i=0 ; i<words.size() ; i++)
//         {
//             j=0, k=0;
//             while(j<s.length() && k<words[i].length())
//             {
//                 if(s[j]==words[i][k])
//                 {
//                     j++;
//                     k++;
//                 }
//                 else
//                 {
//                     j++;
//                 }
//             }
//             if(k==words[i].length())
//                 ans++;
//         }
//         return ans;
//     }
// };




// APPROACH 2 -> TLE
// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int i, j, ans=0;
//         vector<int> dp(words.size(), 0);
//         for(i=0 ; i<s.length() ; i++)
//         {
//             for(j=0 ; j<words.size() ; j++)
//             {
//                 if(s[i]==words[j][dp[j]])
//                 {
//                     dp[j]++;
//                     if(dp[j]==words[j].length())
//                         ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };




// APPROACH 3
class Solution {
private:
    bool check_subsequence(string& s, string& word)
    {
        int i=0, j=0;
        while(i<s.length() && j<word.length())
        {
            if(s[i]==word[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if(j==word.length())
            return true;
        return false;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int i, ans=0;
        unordered_map<string, int> mp;
        for(i=0 ; i<words.size() ; i++)
        {
            if(mp.find(words[i])==mp.end())
            {
                if(check_subsequence(s, words[i]))
                {
                    // 1 signifies that it is a valid subsequnce
                    mp[words[i]] = 1;
                    ans++;
                }
                else
                    // 0 represents that it is not a valid subsequence 
                    mp[words[i]] = 0;
            }
            else if(mp[words[i]]==1)
                ans++;
        }
        return ans;
    }
};