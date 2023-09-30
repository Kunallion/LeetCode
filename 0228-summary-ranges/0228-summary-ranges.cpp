class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string s="";
        int i, flag1=0, flag2=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(flag1==0)
            {
                s += to_string(nums[i]);
                flag1=1;
            }
            else if(flag1==1 && flag2==0 && nums[i]==nums[i-1]+1)
            {
                s += "->";
                flag2=1;
            }
            else if(flag1==1 && nums[i]!=nums[i-1]+1)
            {
                if(flag2==1)
                    s += to_string(nums[i-1]);
                ans.push_back(s);
                s.clear();
                s += to_string(nums[i]);
                flag1=1;
                flag2=0;
            }
            else if(flag1==0 && nums[i]!=nums[i-1]+1)
            {
                ans.push_back(s);
                s.clear();
            }
        }
        if(flag2==1)
        {
            s += to_string(nums[i-1]);
            ans.push_back(s);
        }
        else if(flag1==1)
        {
            ans.push_back(s);
        }
        return ans;
    }
};