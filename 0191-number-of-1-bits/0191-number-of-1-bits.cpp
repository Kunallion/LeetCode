class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i, count=0;
        while(n>0)
        {
            i = n%2;
            n /= 2;
            if(i==1)
                count++;
        }
        return count;
    }
};