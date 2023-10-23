class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int ans=1, count=1;

        for(int i=1 ; i<s.length() ; i++){
            if(s[i]==s[i-1]+1){
                count++;
            }
            else{
                ans = max(ans, count);
                count=1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};