class Solution {
private:
    void solve(vector<int>& nums, set<vector<int>>& s, vector<int> temp, int index){

        // Base Case
        if(index==nums.size()){
            if(temp.size()>1)
                s.insert(temp);
            temp.clear();
            return;
        }

        // exclude case
        solve(nums, s, temp, index+1);

        // include case
        if(temp.size()==0 || nums[index]>=temp[temp.size()-1]){
            temp.push_back(nums[index]);
            solve(nums, s, temp, index+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, s, temp, 0);

        for(auto it:s)
            ans.push_back(it);
        
        return ans;
    }
};