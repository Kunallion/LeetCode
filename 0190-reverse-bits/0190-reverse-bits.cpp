class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i, count=0;
        uint32_t num=0;
        vector<int> arr;
        while(n>0)
        {
            i = n%2;
            n = n/2;
            arr.push_back(i);
            count++;
        }
        if(count<32)
        {
            for(i=0 ; i<32-count ; i++)
            {
                arr.push_back(0);
            }
        }
        for(i=arr.size()-1 ; i>=0 ; i--)
        {
            num += arr[i]*pow(2,arr.size()-1-i);
        }
        return num;
    }
};