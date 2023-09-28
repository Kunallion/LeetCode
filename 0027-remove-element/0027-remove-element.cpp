class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j, count;
        count = nums.size();
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==val)
            {
                nums[i] = 100;
                count--;
            }       
        }
        sort(nums.begin(), nums.end());
        return count;
    }
};