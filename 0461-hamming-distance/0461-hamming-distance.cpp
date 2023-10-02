class Solution {
public:
    int hammingDistance(int x, int y) {
        string s1="";
        string s2="";
        int i, count=0;
        while(x>0)
        {
            s1 += to_string(x%2);
            x /= 2;
        }
        while(y>0)
        {
            s2 += to_string(y%2);
            y /= 2;
        }
        if(s1.length()>s2.length())
        {
            for(i=s2.length() ; i<s1.length() ; i++)
            {
                s2 += '0';
            }
        }
        else if(s1.length()<s2.length())
        {
            for(i=s1.length() ; i<s2.length() ; i++)
            {
                s1 += '0';
            }
        }
        for(i=0 ; i<s1.length() ; i++)
        {
            if(s1[i]!=s2[i])
                count++;
        }
        return count;
    }
};