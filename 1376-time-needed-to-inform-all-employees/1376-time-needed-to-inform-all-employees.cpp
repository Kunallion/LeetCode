class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int maxTime=0;
        for(int i=0 ; i<manager.size() ; i++){
            int j=i;
            int time=0;
            while(manager[j]!=-1){
                time += informTime[manager[j]];
                j = manager[j];
            }
            maxTime = max(maxTime, time);
        }
        return maxTime;
    }
};