class Solution {
public:
    int maxScore(string s) {
        
        int zeros = 0;
        int ones = count(s.begin(), s.end(), '1');
        int maxi = 0;

        for(int i=0 ; i<s.length()-1 ; i++){

            if(s[i]=='0')
                zeros++;
            else if(s[i]=='1')
                ones--;
            
            maxi = max(maxi, zeros+ones);
        }
        return maxi;
    }
};