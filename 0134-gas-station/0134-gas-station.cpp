class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i, ans=0, fuel=0, gas_sum=0, cost_sum=0;
        for(i=0 ; i<gas.size() ; i++)
        {
            gas_sum += gas[i];
            cost_sum += cost[i];
            fuel += gas[i]-cost[i];
            if(fuel<0)
            {
                ans = i+1;
                fuel = 0;
            }
        }
        if(gas_sum<cost_sum)
            return -1;
        return ans;
    }
};