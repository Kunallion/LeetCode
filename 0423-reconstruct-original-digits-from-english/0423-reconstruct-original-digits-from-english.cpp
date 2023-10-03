class Solution {
public:
    string originalDigits(string s) {
        
        int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='z')
                count[0]++;
            if(s[i]=='w')
                count[2]++;
            if(s[i]=='x')
                count[6]++;
            if(s[i]=='s')  // 7 and 6 both have 's'
                count[7]++;
            if(s[i]=='g')
                count[8]++;
            if(s[i]=='u')
                count[4]++;
            if(s[i]=='f') // 4 and 5 both have 'f'
                count[5]++;
            if(s[i]=='h') // both 3 and 8 have 'h'
                count[3]++;
            if(s[i]=='i') // 5, 6, 8, 9
                count[9]++;
            if(s[i]=='o') // 0, 1, 2, 4
                count[1]++;
        }

        count[7] -= count[6];
        count[5] -= count[4];
        count[3] -= count[8];
        count[9]  = count[9] - count[5] - count[6] - count[8];
        count[1] = count[1] - count[0] - count[2] - count[4];

        string ans="";

        for(int i=0 ; i<=9 ; i++){
            for(int j=0 ; j<count[i] ; j++){
                ans += to_string(i);
            }
        }

        return ans;
    }
};