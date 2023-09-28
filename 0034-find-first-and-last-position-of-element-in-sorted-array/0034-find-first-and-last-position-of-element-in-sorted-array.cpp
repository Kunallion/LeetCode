class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i, j, k, start=-1, end=-1, mid, low=0, high = nums.size()-1;
        vector<int> ans;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target && (start==-1 || mid<start))
            {
                start = mid;
                high=mid-1;
            }
            else if(nums[mid]==target && mid==start)
            {
                break;
            }
            else if(nums[mid]<target)
            {
                low++;
            }
            else if(nums[mid]>target)
            {
                high--;
            }
        }
        low=0, high = nums.size()-1;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target && mid>end)
            {
                end = mid;
                low=mid+1;
            }
            else if(nums[mid]==target && mid==end)
            {
                break;
            }
            else if(nums[mid]<target)
            {
                low++;
            }
            else if(nums[mid]>target)
            {
                high--;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};