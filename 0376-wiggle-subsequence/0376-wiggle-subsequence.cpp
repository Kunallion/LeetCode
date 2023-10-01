class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int i, high=1, low=1;
        for(i=1 ; i<nums.size() ; i++)
        {
            if(nums[i]>nums[i-1])
                high = low+1;
            else if(nums[i]<nums[i-1])
                low = high+1;
        }
        return max(low, high);
    }
};