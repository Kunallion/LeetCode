class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        else if(nums[n-1]>nums[n-2])
            return n-1;
        int i, low=1, high=nums.size()-2, mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[mid-1])
                high = mid-1;
            else
                low = mid+1;
        }
        return mid;
    }
};