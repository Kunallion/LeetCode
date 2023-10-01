class Solution {
public:
    int bulbSwitch(int n) {
        int i, count=0;
        if(n==0)
            return 0;
        for(i=1 ; i<=sqrt(n) ; i++)
        {
            if(i*i<=n)
            {
                count++;
            }
            else
                return count;
        }
        return count;
    }
};