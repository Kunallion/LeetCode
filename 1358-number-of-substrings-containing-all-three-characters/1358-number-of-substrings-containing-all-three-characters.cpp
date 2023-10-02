class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int ans=0, indexA = -1, indexB = -1, indexC = -1;
        for(int i=0 ; i<s.length() ; i++){

            if(s[i]=='a')
                indexA = i;
            
            if(s[i]=='b')
                indexB = i;
            
            if(s[i]=='c')
                indexC = i;
            
            ans += min(indexA, min(indexB, indexC)) + 1;
        }
        return ans;
    }
};