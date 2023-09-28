class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, count=0, flag=0;

        for(i=s.length()-1 ; i>=0 ; i--)
        {
            if(s[i]!=' ')
            {
                count++;
                flag=1;
            }
            else if(s[i]==' ' && flag==0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};