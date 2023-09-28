class Solution {
public:
    string countAndSay(int n) {
        string temp, ans = "1";
        n -= 1;
        int i, j;
        while(n--)
        {
            temp = "";
            i=0;
            while(i<ans.length())
            {
                int count=1;
                for(j=i+1 ; j<ans.length() ; j++)
                {
                    if(ans[j]==ans[i])
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                temp += to_string(count);
                temp += ans[i];
                i += count;
            }
            ans = temp;
        }
        return ans;
    }
};