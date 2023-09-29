class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i, mul=1, ans=INT_MIN;
        for(i=0 ; i<nums.size() ; i++)
        {
            mul *= nums[i];
            ans = max(ans, mul);
            if(mul==0)
                mul = 1;
        }
        mul=1;
        for(i=nums.size()-1 ; i>=0 ; i--)
        {
            mul *= nums[i];
            ans = max(ans,mul);
            if(mul==0)
                mul = 1;
        }
        return ans;
    }
};