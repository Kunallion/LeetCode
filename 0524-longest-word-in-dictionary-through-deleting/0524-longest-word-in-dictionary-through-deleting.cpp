class Solution {
private:

    // Checks if the dictionary word text2 is present in our given string text1 or not
    bool check(string text1, string text2){
        int i=0, j=0;
        while(i<text1.length() && j<text2.length()){
            if(text1[i]==text2[j]){
                i++;
                j++;
            }
            else
                i++;
        }
        if(j==text2.length())
            return true;
        return false;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string ans="";

        // We will check for each string in the dictionary whether it is there in s or not
        for(int i=0 ; i<dictionary.size() ; i++){

            // Calling function Check
            if(check(s, dictionary[i])){
                
                //If dictionary word length is greater than the ans length then update it
                if(dictionary[i].length()>ans.length())
                    ans = dictionary[i];

                // Lexigraphically smaller word is taken if the length of words are same
                else if(dictionary[i].length()==ans.length() && ans>dictionary[i])
                    ans = dictionary[i];
            }
        }
        return ans;
    }
};