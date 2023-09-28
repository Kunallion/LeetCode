class Solution {
public:
    int strStr(string haystack, string needle) {
        // size_t found = str.find(str1);
        // if (found != string::npos)
        //     return found;
        // return -1;

        int i, j;
        int lps[needle.size()];
        lps[0] = 0;

        for(i=1 ; i<needle.size() ; i++)
        {
            int j=lps[i-1];
            while(j>0 && needle[i]!=needle[j])
            {
                j = lps[j-1];
            }
            if(needle[i]==needle[j])
            {
                j++;
            }
            lps[i] = j;
        }
        
        i=0, j=0;
        while(i<haystack.length())
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
                if(j==needle.length())
                {
                    return (i-j);
                }
            }
            else
            {
                if(j>0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};