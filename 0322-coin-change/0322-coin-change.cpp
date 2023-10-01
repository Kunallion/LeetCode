// Using Recursion -> TLE
// class Solution {
// private:
//     int solve(vector<int>& coins, int sum)
//     {
//         // Base Case
//         if(sum==0)
//             return 0;
//         if(sum<0)
//             return INT_MAX;

//         int mini = INT_MAX;

//         for(int i=0 ; i<coins.size() ; i++)
//         {
//             int ans = solve(coins, sum-coins[i]);
//             if(ans!=INT_MAX)
//                 mini = min(mini, 1+ans);
//         }
//         return mini;
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {

//         int ans = solve(coins, amount);

//         if(ans==INT_MAX)
//             ans = -1;
//         return ans;
//     }
// };


// Using DP -> Memoization top-down Approach
// class Solution {
// private:
//     int solve(vector<int>& coins, vector<int>& dp, int sum)
//     {
//         // Base Case
//         if(sum==0)
//             return 0;
//         if(sum<0)
//             return INT_MAX;
//         if(dp[sum]!=-1)
//             return dp[sum];

//         int mini = INT_MAX;

//         for(int i=0 ; i<coins.size() ; i++)
//         {
//             int ans = solve(coins, dp, sum-coins[i]);
//             if(ans!=INT_MAX)
//                 mini = min(mini, 1+ans);
//         }
//         dp[sum] = mini;
//         return mini;
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount+1, -1);
//         int ans = solve(coins, dp, amount);

//         if(ans==INT_MAX)
//             ans = -1;
//         return ans;
//     }
// };



// Using DP -> Tabulation top-down Approach
class Solution {
private:
    int solve(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i=1 ; i<=amount ; i++)
        {
            for(int j=0 ; j<coins.size() ; j++)
            {
                if((i-coins[j])>=0 && dp[i-coins[j]]!=INT_MAX)
                {
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());

        if(solve(coins, amount)==INT_MAX)
            return -1;
        return solve(coins, amount);
    }
};