class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, profit=0, buy=-1;

        for(i=0 ; i<prices.size()-1 ; i++)
        {
            if(prices[i]<prices[i+1] && buy==-1)
                buy = prices[i];
            else if(prices[i]>prices[i+1] && buy!=-1)
            {
                profit += prices[i]-buy;
                buy=-1;
            }
        }
        if(buy!=-1)
            profit += prices[prices.size()-1] - buy;
        return profit;
    }
};