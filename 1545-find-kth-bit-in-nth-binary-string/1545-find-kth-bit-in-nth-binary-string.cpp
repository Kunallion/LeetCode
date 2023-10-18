class Solution {
private:
    string reverseString(string s){
        reverse(s.begin(), s.end());
        return s;
    }
    string invertString(string s){
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }
public:
    char findKthBit(int n, int k) {
        
        string s = "0";
        for(int i=1 ; i<=n ; i++){
            string invert = invertString(s);
            string rev = reverseString(invert);

            s += '1';
            s += rev;

            if(s.length()>=k){
                return s[k-1];
            }
        }
        return s[k-1];
    }
};