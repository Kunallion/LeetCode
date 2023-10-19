class Solution {
private:
    bool removeChar(string s, int index){
        s.erase(s.begin()+index);
        string str = s;
        reverse(str.begin(), str.end());
        if(s==str)
            return true;
        return false;
    }
public:
    bool validPalindrome(string s) {
        
        int count=0;
        for(int i=0 ; i<s.length()/2 ; i++){
            if(s[i]!=s[s.length()-1-i]){
                if(removeChar(s, i)==true || removeChar(s, s.length()-1-i)==true)
                    return true;
                return false;
            }
        }
        return true;
    }
};