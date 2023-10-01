class Solution {
public:
    string reverseVowels(string s) {
        int i, j=0;
        string vowel="";
        for(i=0 ; i<s.length() ; i++)
        {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U')
            {
                vowel += s[i];
            }
        }
        reverse(vowel.begin(), vowel.end());
        for(i=0  ; i<s.length() ; i++)
        {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U')
            {
                s[i] = vowel[j];
                j++;
            }
        }
        return s;
    }
};