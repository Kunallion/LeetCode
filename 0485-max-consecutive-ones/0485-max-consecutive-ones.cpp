class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, count=0, maxcount=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==1)
                count++;
            else
            {
                maxcount = max(maxcount, count);
                count=0;
            }
        }
        maxcount = max(maxcount, count);
        return maxcount;
    }
};