class Solution {
public:
    int findComplement(int num) {
        int n=0, i, x=0;
        while(num>0)
        {
            i = num%2;
            if(i==0)
            {
                n += pow(2,x);
            }
            num /= 2;
            x++;
        }
        return n;
    }
};