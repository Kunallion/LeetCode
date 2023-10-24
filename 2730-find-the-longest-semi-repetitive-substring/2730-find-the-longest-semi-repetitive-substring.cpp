class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        int maxlen=0, len=1, flag=0;
        for(int i=1 ; i<s.length() ; i++){
            len=1;
            flag=0;
            for(int j=i ; j<s.length() ; j++){
                if(s[j]==s[j-1] && flag==0){
                    len++;
                    flag=1;
                }
                else if(s[j]==s[j-1] && flag==1){
                    maxlen = max(maxlen, len);
                    len=2;
                }
                else{
                    len++;
                }
            }
            maxlen = max(maxlen, len);
        }
        maxlen = max(maxlen, len);
        return maxlen;
    }
};