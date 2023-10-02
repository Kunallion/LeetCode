class Solution {
public:
    int arrangeCoins(int n) {
        int ans=5;
        long long unsigned int c = n;
        ans = (1+sqrt(1+8*1*c))/2;
        return ans-1;
    }
};