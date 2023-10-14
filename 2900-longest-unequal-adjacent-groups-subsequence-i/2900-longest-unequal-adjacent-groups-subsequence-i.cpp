class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<int> arr;
        vector<int> temp;
        vector<string> ans;
        
        for(int i=0 ; i<groups.size()-arr.size() ; i++){
            temp.push_back(i);
            for(int j=i+1 ; j<groups.size() ; j++){
                if(groups[j]!=groups[temp[temp.size()-1]]){
                    temp.push_back(j);
                }
            }
            if(temp.size()>arr.size()){
                arr = temp;
            }
            temp.clear();
        }
        
        for(int i=0 ; i<arr.size() ; i++){
            ans.push_back(words[arr[i]]);
        }
        
        return ans;
    }
};