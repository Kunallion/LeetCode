class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i, flag=0;
        for(i=1 ; i<nums.size() ; i++)
        {
            if(nums[i]-nums[i-1]>0 && flag==0)
            {
                flag = 1;
            }
            else if(nums[i]-nums[i-1]<0 && flag==0)
            {
                flag = 2;
            }
            else if(nums[i]-nums[i-1]>0 && flag==2 || nums[i]-nums[i-1]<0 && flag==1)
            {
                return false;
            }
        }
        return true;
    }
};