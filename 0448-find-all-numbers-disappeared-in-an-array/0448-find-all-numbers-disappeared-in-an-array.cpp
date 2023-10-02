class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0 ; i<nums.size() ; i++)
        {
            m[i+1]++;
            m[nums[i]]++;
        }
        nums.clear();
        for( auto it:m)
        {
            if(it.second==1)
            {
                nums.push_back(it.first);
            }
        }
        return nums;
    }
};