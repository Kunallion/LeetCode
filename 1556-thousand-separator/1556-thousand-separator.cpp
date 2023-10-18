class Solution {
public:
    string thousandSeparator(int n) {
        
        // base case
        if(n==0)
            return "0";
            
        string ans = "";
        int i, count=0;
        while(n>0){
            if(count==3){
                ans += '.';
                count=0;
            }
            i = n%10;
            n /= 10;
            ans += to_string(i);
            count++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};