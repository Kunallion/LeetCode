class Solution {
private:
    void solve(unordered_map<string, int>& mp, int index, string s, string& ans){

        // Base Case
        if(index==s.length()){
            if(mp.find(s)==mp.end()){
                ans = s;
            }
            return;
        }

        // Check if we already got a valid ans
        if(ans.length()>0)
            return;
        
        for(int i=index ; i<s.length() ; i++){
            s[i] = '1';
            solve(mp, i+1, s, ans);

            // Backtracking
            s[i] = '0';
        }
        return;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        // Base case
        if(nums.size()==1 && nums[0]=="1")
            return "0";

        // Store all strings in map for easier searching
        unordered_map<string, int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }

        // make a string with all zeros of length nums.size()
        string s="";
        for(int i=0 ; i<nums.size() ; i++){
            s += '0';
        }
        
        // Ans will be updated, as soon as we get our first binary string not present in map
        string ans="";
        solve(mp, 0, s, ans);

        // return the ans
        return ans;
    }
};