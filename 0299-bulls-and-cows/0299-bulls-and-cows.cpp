class Solution {
public:
    string getHint(string secret, string guess) {
        int i, j, x=0, y=0;
        string ans = "";
        for(i=0 ; i<secret.length() ; i++)
        {
            if(secret[i]==guess[i])
            {
                x++;
                secret[i] = -1;
                guess[i] = -1;
            }
        }
        ans += to_string(x);
        ans += 'A';
        for(i=0 ; i<secret.length() ; i++)
        {
            for(j=0 ; j<guess.length() ; j++)
            {
                if(secret[i]==guess[j] && guess[j]!=-1)
                {
                    y++;
                    guess[j]=-1;
                    break;
                }
            }
        }
        ans += to_string(y);
        ans += 'B';
        return ans;
    }
};