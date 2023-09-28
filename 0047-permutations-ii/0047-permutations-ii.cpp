class Solution {
private:
    void solve(vector<int> nums, set<vector<int>>& s, int index)
    {
        // Base Case
        if(index>=nums.size())
        {
            s.insert(nums);
            return;
        }

        for(int i=index ; i<nums.size() ; i++)
        {
            swap(nums[i], nums[index]);
            solve(nums, s, index+1);

            // BackTracking
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int index=0;

        solve(nums, s, index);

        for(auto it:s)
            ans.push_back(it);
        
        return ans;
    }
};