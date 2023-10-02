class Solution {
public:
    int countSegments(string s) {
        int i, count=0;
        for(i=0 ; i<s.length() ; i++)
        {
            if(i==0 && s[i]!=' ')
                count++;
            else if(i<s.length()-1 && s[i]==' ' && s[i+1]!=' ')
                count++;
        }
        return count;
    }
};