class Solution {
private:
    int solve(vector<int>& nums, int index, vector<int>& dp)
    {
        // Base Case
        if(index>=nums.size()-1)
            return 0;

        if(dp[index]!=INT_MAX-1)
            return dp[index];
        
        for(int i=1 ; i<=nums[index] ; i++)
        {
            dp[index] = min(dp[index], 1 + solve(nums, index+i, dp));
        }
        return dp[index];
    }
public:
    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), INT_MAX-1);
        return solve(nums, 0, dp);
    }
};