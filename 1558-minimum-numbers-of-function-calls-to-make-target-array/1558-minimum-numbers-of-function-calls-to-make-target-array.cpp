class Solution {
public:
    int minOperations(vector<int>& nums) {
        int no_of_ones=0, maxlen=1, bits_len=0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            bits_len=0;
            while(nums[i]>0)
            {
                no_of_ones += nums[i]&1;
                bits_len++;
                nums[i]>>=1;
            }
            maxlen = max(maxlen, bits_len);
        }
        return no_of_ones + maxlen - 1;
    }
};