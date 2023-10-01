class Solution {
public:
    vector<int> arr;
    vector<int> num;
    Solution(vector<int>& nums) {
        arr = nums;
        num = nums;
    }
    
    vector<int> reset() {
        return num;
    }
    
    vector<int> shuffle() {
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */