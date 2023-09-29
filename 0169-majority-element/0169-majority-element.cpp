class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, element, count=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(count==0)
            {
                element = nums[i];
                count++;
            }
            else if(element==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return element;
    }
};