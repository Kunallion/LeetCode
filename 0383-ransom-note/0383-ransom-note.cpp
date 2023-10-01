class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i, count=0;
        unordered_map<char,int> m;
        for(i=0 ; i<ransomNote.length() ; i++)
        {
            m[ransomNote[i]]++;
        }
        for(auto it:m)
        {
            count=0;
            for(i=0 ; i<magazine.length() ; i++)
            {
                if(magazine[i]==it.first)
                    count++;
            }
            if(count<it.second)
                return false;
        }
        return true;
    }
};