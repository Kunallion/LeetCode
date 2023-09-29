class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i, ans=0;
        for(i=columnTitle.length()-1 ; i>=0 ; i--)
        {
            if(i==columnTitle.length()-1)
            {
                ans += ((int)columnTitle[i]-64);
            }
            else
            {
                ans += ((int)columnTitle[i]-64)*pow(26,(columnTitle.length()-1-i));
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};