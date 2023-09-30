class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int i, el1=INT_MIN, el2=INT_MIN, count1=0, count2=0;
        vector<int> ans;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(count1==0 && nums[i]!=el2)
            {
                el1 = nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!=el1)
            {
                el2 = nums[i];
                count2++;
            }
            else if(nums[i]==el1)
            {
                count1++;
            }
            else if(nums[i]==el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0, count2=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==el1)
                count1++;
            else if(nums[i]==el2)
                count2++;
        }
        int mini = nums.size()/3;
        if(count1>mini)
            ans.push_back(el1);
        if(count2>mini)
            ans.push_back(el2);
        return ans;
    }
};