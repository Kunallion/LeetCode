class Solution {
public:
    int minimumSum(int n, int k) {
        
        int num=1, sum=0;
        unordered_set<int> set;

        while(set.size()<n){
            if(set.find(k-num)==set.end()){
                set.insert(num);
                sum += num;
                num++;
            }
            else{
                num++;
            }
        }

        return sum;
    }
};