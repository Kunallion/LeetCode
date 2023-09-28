class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=nums.size();

        if(nums.size()<3)
            return nums.size();
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(i<nums.size()-2)
            {
                if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
                {
                    nums.erase(nums.begin()+i);
                    k--;
                    i--;
                }
            }
        }
        return k;
    }
};