class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i;
        string temp;
        set<string> set1, set2;
        if(s.length()<=10)
            return {};
        for(i=0 ; i<s.size()-9 ; i++)
        {
            temp = s.substr(i, 10);
            if(set1.find(temp)!=set1.end())
            {
                set2.insert(temp);
            }
            set1.insert(temp);
        }
        vector<string> ans(set2.begin(), set2.end());
        return ans;
    }
};