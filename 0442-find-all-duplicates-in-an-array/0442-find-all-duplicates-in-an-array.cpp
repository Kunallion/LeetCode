class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(s.count(nums[i])>0)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        return ans;
    }
};