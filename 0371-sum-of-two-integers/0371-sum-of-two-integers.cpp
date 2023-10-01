class Solution {
public:
    int getSum(int a, int b) {
        int num=abs(b);
        while(num--)
        {
            if(b<0)
            {
                a--;
            }
            else
            {
                a++;
            }
        }
        return a;
    }
};