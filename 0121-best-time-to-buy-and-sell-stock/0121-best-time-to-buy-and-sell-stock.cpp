class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, maxprofit=0, mini=prices[0];
        for(i=1 ; i<prices.size() ; i++)
        {
            mini = min(mini, prices[i]);
            maxprofit = max(maxprofit, prices[i]-mini);
        }
        return maxprofit;
    }
};