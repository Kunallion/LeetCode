class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i, j, k=0;
        string str="";
        for(i=0 ; i<s.length()/2 ; i++)
        {
            str += s[i];
            k=0;
            if(s.length()%str.length()==0)
            {
                while(true)
                {
                    for(j=0+k*str.length() ; j<(k+1)*str.length() ; j++)
                    {
                        if(s[j]!=str[j-k*str.length()])
                            break;
                    }
                    if(j==s.length())
                    {
                        return true;
                    }
                    else if(j==(k+1)*str.length())
                    {
                        k++;
                    }
                    else if(j<(k+1)*str.length() || (k+1)*str.length()>s.length())
                    {
                        break;
                    }
                }
            }
        }
        return false;
    }
};