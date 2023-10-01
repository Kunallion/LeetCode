class Solution {
public:
    bool isPerfectSquare(int num) {
        long int low=0, high=num, mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(mid*mid==num)
                return true;
            else if(mid*mid<num)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};