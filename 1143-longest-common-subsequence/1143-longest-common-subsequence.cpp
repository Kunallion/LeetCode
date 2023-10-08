class Solution {
private:
    int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        
        // Base Case
        if(i==text1.length() || j==text2.length())
            return 0;
        
        // Check Condition
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        // Match Found Condition
        if(text1[i]==text2[j])
            dp[i][j] = 1 + lcs(text1, text2, i+1, j+1, dp);
        
        // Match Not Found Condition
        else
            dp[i][j] = max(lcs(text1, text2, i+1, j, dp), lcs(text1, text2, i, j+1, dp));
        
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return lcs(text1, text2, 0, 0, dp);
    }
};