class Solution {
public:
    double myPow(double x, long long n) {
        int flag=0;
        double ans=1;
        if(n<0)
            flag=1;;
        n = abs(n);
        while(n>0)
        {
            if(n%2==0)
            {
                x *= x;
                n /= 2;
            }
            else
            {
                ans *= x;
                n -= 1;
            }
        }
        if(flag==1)
            ans = 1/ans;
        return ans;
    }
};