// // Using Recursion -> TLE
// class Solution {
// private:
//     int solve(vector<int>& nums, int target)
//     {
//         // BASE CASE
//         if(target==0)
//             return 1;
//         if(target<0)
//             return 0;

//         int ans=0;
//         for(int i=0 ; i<nums.size() ; i++)
//         {
//             ans += solve(nums, target-nums[i]);
//         }
//         return ans;
//     }
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         return solve(nums, target);
//     }
// };




// // USING MEMOIZATION
// class Solution {
// private:
//     int solveMem(vector<int>& nums, int target, vector<int>& dp)
//     {
//         // BASE CASE
//         if(target==0)
//             return 1;
//         if(target<0)
//             return 0;
//         if(dp[target]!=-1)
//             return dp[target];

//         int ans=0;
//         for(int i=0 ; i<nums.size() ; i++)
//         {
//             ans += solveMem(nums, target-nums[i], dp);
//         }
//         dp[target] = ans;
//         return dp[target];
//     }
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> dp(target+1, -1);
//         return solveMem(nums, target, dp);
//     }
// };




// USING TABULATION
class Solution {
private:
    int solveTab(vector<int>& nums, int target)
    {
        vector<unsigned long long> dp(target+1);
        dp[0] = 1;
        
        for(int i=1 ; i<=target ; i++)
        {
            for(int j=0 ; j<nums.size() ; j++)
            {
                if((i-nums[j])>=0)
                {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solveTab(nums, target);
    }
};