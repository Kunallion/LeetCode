// RECURSION -> TLE
// class Solution {
// private:
//     int solve(vector<vector<char>>& matrix, int i, int j, int& maxi)
//     {
//         // BASE CASE
//         if(i>=matrix.size() || j>=matrix[0].size())
//             return 0;
        
//         int right = solve(matrix, i, j+1, maxi);
//         int down = solve(matrix, i+1, j, maxi);
//         int diagonal = solve(matrix, i+1, j+1, maxi);

//         if(matrix[i][j]=='1')
//         {
//             int ans = 1 + min(right, min(down, diagonal));
//             maxi = max(ans, maxi);
//             return ans;
//         }
//         else
//             return 0;
//     }
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int maxi=0;
//         solve(matrix, 0, 0, maxi);
//         return maxi*maxi;
//     }
// };




// USING MEMOIZATION
class Solution {
private:
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi, vector<vector<int>>& dp)
    {
        // BASE CASE
        if(i>=matrix.size() || j>=matrix[0].size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right = solve(matrix, i, j+1, maxi, dp);
        int down = solve(matrix, i+1, j, maxi, dp);
        int diagonal = solve(matrix, i+1, j+1, maxi, dp);

        if(matrix[i][j]=='1')
        {
            dp[i][j] = 1 + min(right, min(down, diagonal));
            maxi = max(dp[i][j], maxi);
            return dp[i][j];
        }
        else
            return 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxi=0;
        solve(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
    }
};