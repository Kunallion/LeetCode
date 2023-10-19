class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i;
        for(i=0 ; i<s.length() ; i++)
        {
            if(s[i]=='#' && i>0)
            {
                s.erase(s.begin()+i);
                s.erase(s.begin()+i-1);
                i -= 2;
            }
            else if(s[i]=='#')
            {
                s.erase(s.begin()+i);
                i--;
            }
        }
        for(i=0 ; i<t.length() ; i++)
        {
            if(t[i]=='#' && i>0)
            {
                t.erase(t.begin()+i);
                t.erase(t.begin()+i-1);
                i -= 2;
            }
            else if(t[i]=='#')
            {
                t.erase(t.begin()+i);
                i--;
            }
        }
        cout<<s<<" "<<t<<endl;
        if(s==t)
            return true;
        return false;
    }
};