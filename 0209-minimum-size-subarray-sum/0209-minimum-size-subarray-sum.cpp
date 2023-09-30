class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, sum=0, n=nums.size(), ans=INT_MAX;
        for(i=0 ; i<n ; i++)
        {
            sum += nums[i];
            if(sum>=target)
            {
                ans = min(ans, i-j+1);
                while(sum>=target)
                {
                    sum -= nums[j];
                    ans = min(ans, i-j+1);
                    j++;
                }
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};