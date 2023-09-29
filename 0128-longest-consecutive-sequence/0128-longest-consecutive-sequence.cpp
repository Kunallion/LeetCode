class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i, num, count=0, max_len=0;
        unordered_set<int> s;
        for(i=0 ; i<nums.size() ; i++)
        {
            s.insert(nums[i]);
        }
        for(auto it:s)
        {
            if(s.find(it-1)==s.end())
            {
                count=1;
                num = it;
                while(s.find(num+1)!=s.end())
                {
                    count++;
                    num++;
                }
                max_len = max(max_len, count);
            }
        }
        return max_len;
    }
};