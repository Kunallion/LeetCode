class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int i, max=INT_MIN;
        sort(nums.begin(), nums.end());
        if(nums.size()<2)
            return 0;
        for(i=0 ; i<nums.size()-1 ; i++)
        {
            if((nums[i+1]-nums[i])>max)
                max = (nums[i+1]-nums[i]);
        }
        return max;
    }
};