class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        int i, j, new_num=0;
        mp[n] = 1;

        while(true)
        {
            new_num=0;
            while(n>0)
            {
                j = n%10;
                n /= 10;
                new_num += j*j;
            }
            n = new_num;
            if(new_num==1)
                return true;
            else if(mp.find(new_num)!=mp.end())
                return false;
            else
                mp[new_num] = 1;
        }
        return true;
    }
};