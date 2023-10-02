class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        vector<long long> ans;
        long long sum = finalSum;
        
        // for odd sum, the ans will be always 0
        if(sum%2==1)
            return ans;
        
        // for even sum
        for(int i=2 ; i<=sum ; i += 2){      
            if((sum-i)>i){
                sum -= i;
                ans.push_back(i);
            }
            else{
                ans.push_back(sum);
                break;
            }
        }

        return ans;
    }
};