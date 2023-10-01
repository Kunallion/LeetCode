class Solution {
public:
    string reverseWords(string s) {
        int i;
        string reversed_string="";
        string temp;
        for(i=0 ; i<s.length() ; i++)
        {
            if(s[i]==' ')
            {
                reverse(temp.begin(), temp.end());
                reversed_string += temp;
                reversed_string += ' ';
                temp.clear();
            }
            else
            {
                temp += s[i];
            }
        }
        reverse(temp.begin(), temp.end());
        reversed_string += temp;
        temp.clear();
        return reversed_string;
    }
};