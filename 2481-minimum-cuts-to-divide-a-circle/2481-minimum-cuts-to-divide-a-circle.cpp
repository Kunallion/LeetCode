class Solution {
public:
    int numberOfCuts(int n) {
        
        // n=1, means no division of circles, therefore 0 cuts
        if(n==1)
            return 0;
        
        // if n is even then we just need n/2 cuts
        if(n%2==0)
            return n/2;
        
        // For all odd values of n, except 1, we need exactly n cuts to divide a circle in n equal parts
        return n;
    }
};