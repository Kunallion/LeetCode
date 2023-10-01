class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    int pick(int target) {
        int i;
        while(true)
        {
            i = rand()%arr.size();
            if(arr[i]==target)
                break;
        }
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */