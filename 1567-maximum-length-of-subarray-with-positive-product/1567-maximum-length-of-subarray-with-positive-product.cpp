class Solution {
private:
    int getLength(vector<int>& temp, int neg){
        int len;

        // If the number of negatives is even, then no problem as it becomes positive product
        if(neg%2==0){
            len = temp.size();
        }

        // If the number of negatives is odd, check length from fwd and back
        else{
            int fwd, back;

            for(int j=0 ; j<temp.size() ; j++){
                if(temp[j]<0){
                    fwd = j;
                    break;
                }
            }

            for(int j=temp.size()-1 ; j>=0 ; j--){
                if(temp[j]<0){
                    back = j;
                    break;
                }
            }

            fwd = temp.size()-1-fwd;
            len = max(fwd, back);
        }
        return len;
    }
public:
    int getMaxLen(vector<int>& nums) {
        
        vector<int> temp;
        int neg=0, len=0, maxlen=0;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                maxlen = max(maxlen, getLength(temp, neg));
                neg=0;
                temp.clear();
            }
            else if(i==nums.size()-1){
                temp.push_back(nums[i]);
                if(nums[i]<0)
                    neg++;
                maxlen = max(maxlen, getLength(temp, neg));
            }
            else{
                temp.push_back(nums[i]);
                if(nums[i]<0)
                    neg++;
            }
        }
        
        return maxlen;
    }
};