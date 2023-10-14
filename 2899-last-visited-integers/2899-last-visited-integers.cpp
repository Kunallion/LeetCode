class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        
        vector<int> ans;
        vector<int> arr;
        
        int i=0; 
        while(i<words.size()){
            if(words[i]!="prev"){
                arr.push_back(stoi(words[i]));
                i++;
            }
            else{
                int k=arr.size()-1;
                while(i<words.size() && words[i]=="prev"){
                    if(k>=0){
                        ans.push_back(arr[k]);
                        k--;
                    }
                    else{
                        ans.push_back(-1);
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};