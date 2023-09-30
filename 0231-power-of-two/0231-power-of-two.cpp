class Solution {
public:
    bool isPowerOfTwo(int n) {
        long int num=1;
        while(true)
        {
            if(n==num)
                return true;
            else if(n<num)
                return false;
            else
                num *= 2;
        }
        return true;
    }
};