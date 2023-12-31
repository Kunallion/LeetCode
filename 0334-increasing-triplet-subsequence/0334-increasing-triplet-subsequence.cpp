class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i, num1=INT_MAX, num2=INT_MAX;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]>num2)
                return true;
            else if(nums[i]>num1 && nums[i]<num2)
                num2 = nums[i];
            if(nums[i]<num1)
                num1 = nums[i];
        }
        return false;
    }
};