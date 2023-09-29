// class Solution {
// private:
//     void solve(int index, vector<int>& nums1, vector<int>& nums2, int k, int sum, int mini, int& ans, int count)
//     {
//         if(index==nums1.size() || count==k)
//         {
//             if(count==k)
//             {
//                 // cout<<sum<<endl<<mini<<endl;
//                 sum = sum*mini;
//                 ans = max(ans, sum);
//             }
//             return;
//         }

//         // include part
//         sum += nums1[index];
//         count++;
//         solve(index+1, nums1, nums2, k, sum, min(mini, nums2[index]), ans, count);

//         // backtracking
//         sum -= nums1[index];
//         count--;

//         // exclude part
//         solve(index+1, nums1, nums2, k, sum, mini, ans, count);

//         return;
//     }
// public:
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
//         int ans=0;
//         int mini = INT_MAX;
//         int sum=0;
//         int count=0;

//         solve(0, nums1, nums2, k, sum, mini, ans, count);

//         return ans;
//     }
// };






class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>> arr;
        for(int i=0 ; i<nums1.size() ; i++){
            arr.push_back({nums2[i], nums1[i]});
            // we are keeping nums2[i] before, because it will have higher impact on our    answer as it is getting multiplied with the nums1 sum
        }

        sort(arr.begin(), arr.end(), greater<pair<int,int>>());
        long long sum=0, ans=0;

        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0 ; i<arr.size() ; i++){
            pq.push(arr[i].second);
            sum += arr[i].second;

            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans = max(ans, sum*arr[i].first);
        }
        return ans;
    }
};