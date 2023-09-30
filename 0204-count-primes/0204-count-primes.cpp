class Solution {
public:
    int countPrimes(int n) {
        int i, j, count=0;
        vector<bool> arr(n+1, true);
        for(i=2 ; i<n ; i++)
        {
            if(arr[i])
            {
                count++;
                for(j=2*i ; j<n ; j+=i)
                {
                    arr[j] = false;
                }
            }
        }
        return count;
    }
};