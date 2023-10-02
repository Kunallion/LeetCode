class Solution {
public:
    string reformat(string s) {
        
        string charStr = "";
        string numStr = "";
        string ans = "";

        for(int i=0 ; i<s.length() ; i++){
            if(s[i]>=48 && s[i]<=57)
                numStr += s[i];
            else
                charStr += s[i];
        }

        int i=0, j=0;
        while(i<charStr.length() && j<numStr.length()){
            ans += charStr[i];
            ans += numStr[j];
            i++;
            j++;
        }

        if(i<charStr.length())
            ans += charStr[i];
        else if(j<numStr.length())
            ans.insert(ans.begin()+0, numStr[j]);

        if(ans.length()==s.length())
            return ans;
        
        return "";
    }
};