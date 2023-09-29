class Solution {
public:
    bool isPalindrome(string s) {
        int count=0;
        for(int i=0 ; i<s.length() ; i++)
        {
            if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9'))
            {
                s[count++] = s[i];
            }
        }
        s.resize(count);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str = s;
        reverse(s.begin(), s.end());
        if(s==str)
            return true;
        return false;
    }
};