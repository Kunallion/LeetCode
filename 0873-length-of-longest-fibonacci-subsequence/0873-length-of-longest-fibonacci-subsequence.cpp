class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        
        int count=0, ans=0;
        unordered_set<int> s;
        for(int i=0 ; i<arr.size() ; i++){
            s.insert(arr[i]);
        }

        for(int i=0 ; i<arr.size()-1 ; i++){
            for(int j=i+1 ; j<arr.size() ; j++){

                int a = arr[i];
                int b = arr[j];
                int sum = a+b;
                count=2;

                while(s.find(sum)!=s.end()){
                    count++;
                    a = b;
                    b = sum;
                    sum = a+b;
                }
                ans = max(ans, count);
            }
        }
        if(ans<3)
            return 0;
        return ans;
    }
};