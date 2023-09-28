// Using Recursion - TLE
// class Solution {
// private:
//     void solve(int n, int i, int &count)
//     {
//         if(i == n)
//         {
//             count++;
//             return;
//         }
//         if(i>n)
//             return;

//         solve(n, i+1, count);
//         solve(n, i+2, count);
//     }
// public:
//     int climbStairs(int n) {

//         if(n<=1)
//             return n;
        
//         int count=0;
//         solve(n, 1, count);
//         solve(n, 2, count);

//         return count;
//     }
// };



// Using DP -> Tabulation
// class Solution {
// private:
//     int solve(int n)
//     {
//         vector<int> dp(n+1);
//         dp[1] = 1;
//         dp[2] = 2;

//         for(int i=3 ; i<=n ; i++)
//         {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// public:
//     int climbStairs(int n) {

//         if(n==1)
//             return n;
        
//         return solve(n); 
//     }
// };



// Using DP -> Memoization
// class Solution {
// private:
//     int solve(int n, vector<int>& dp)
//     {
//         if(n<=1)
//         {
//             dp[n] = 1;
//             return dp[n];
//         }

//         if(dp[n]!=-1)
//             return dp[n];
        
//         dp[n] = solve(n-1, dp) + solve(n-2, dp);
//         return dp[n];
//     }
// public:
//     int climbStairs(int n) {

//         if(n==1)
//             return n;
        
//         vector<int> dp(n+1, -1);
//         solve(n, dp);

//         return dp[n]; 
//     }
// };



// Using Space Optimization
class Solution {
public:
    int climbStairs(int n) {

        if(n==1)
            return n;
        
        int prev1 = 1;
        int prev2 = 1;
        int curr;

        for(int i=2 ; i<=n ; i++)
        {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};