class Solution {
public:
    string breakPalindrome(string palindrome) {

        // If the length is 1,then it is always palindrome, therefore we return an empty string
        if(palindrome.length()==1)
            return "";
        
        for(int i=0 ; i<palindrome.length() ; i++){

            // we don't have to change the middle element, as it will still be a palindrome
            if(palindrome[i]!='a' && i!=palindrome.length()/2){
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // If all chars are 'a', then we change the last char to 'b'
        palindrome[palindrome.length()-1] = 'b';

        return palindrome;
    }
};