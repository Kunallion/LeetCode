class Solution {
private:
    // Function to check if it is possible to have "mid" as the maximum smallest absolute difference
    bool isPossible(vector<int>& price, int mid, int k){
        int count = 1, last = price[0];
        for(int i=1 ; i<price.size() ; i++){
            if(price[i]-last>=mid){
                count++;
                last = price[i];
            }
            if(count==k)
                return true;
        }
        return false;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        
        // Sort the prices in ascending order
        sort(price.begin(), price.end());
        int ans=0;
        int low=0;
        int high=price[price.size()-1]-price[0];
        int mid;

        while(low<=high){

            mid = (low + (high-low)/2);
            // Check if it is possible to have "mid" value as the ans
            if(isPossible(price, mid, k)){
                // If true then update ans to mid, and now check for value higher than mid
                ans = mid;
                low = mid+1;
            }
            else{
                // If false, then we need to check for smaller value
                high = mid-1;
            }
        }
        return ans;
    }
};