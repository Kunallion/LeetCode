class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, maxi=INT_MIN, sum=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            sum = max(nums[i], sum+nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};