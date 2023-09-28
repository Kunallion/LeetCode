class Solution {
public:
    string addBinary(string a, string b) {
        int i, j=0, k, len;
        string c="";
        
        
        if(a.length()>=b.length())
        {
            len = a.length();
            reverse(b.begin(), b.end());
            for(i=b.length() ; i<a.length() ; i++)
            {
                b.append("0");
            }
            reverse(b.begin(), b.end());
        }
        else
        {
            len = b.length();
            reverse(a.begin(), a.end());
            for(i=a.length() ; i<b.length() ; i++)
            {
                a.append("0");
            }
            reverse(a.begin(), a.end());
        }
        
        for(i=len-1 ; i>=0 ; i--)
        {
            if(a[i]=='1' && b[i]=='1' && j==0)
            {
                c.append("0");
                j = 1;
            }
            else if(a[i]=='1' && b[i]=='0' && j==0)
            {
                c.append("1");
            }
            else if(a[i]=='0' && b[i]=='1' && j==0)
            {
                c.append("1");
            }
            else if(a[i]=='0' && b[i]=='0' && j==0)
            {
                c.append("0");
            }
            else if(a[i]=='1' && b[i]=='1' && j==1)
            {
                c.append("1");
                j = 1;
            }
            else if(a[i]=='1' && b[i]=='0' && j==1)
            {
                c.append("0");
                j = 1;
            }
            else if(a[i]=='0' && b[i]=='1' && j==1)
            {
                c.append("0");
                j = 1;
            }
            else if(a[i]=='0' && b[i]=='0' && j==1)
            {
                c.append("1");
                j = 0;
            }
        }
        if(j==1)
        {
            c.append("1");
        }
        reverse(c.begin(), c.end());
        return c;
    }
};