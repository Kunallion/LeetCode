class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        map<int,int> mp;
        for(int i=0 ; i<hand.size() ; i++){
            mp[hand[i]]++;
        }

        int count=0, prev;
        while(mp.size()>0 && true){
            for(auto it:mp){
                if(count==0){
                    count++;
                    prev=it.first;
                    mp[it.first]--;
                    if(mp[it.first]==0){
                        mp.erase(it.first);
                    }
                    if(count==groupSize){
                        count=0;
                        break;
                    }
                }
                else if(it.first==prev+1){
                    prev = it.first;
                    mp[it.first]--;
                    if(mp[it.first]==0){
                        mp.erase(it.first);
                    }
                    count++;
                    if(count==groupSize){
                        count=0;
                        break;
                    }
                }
                
                else{
                    return false;
                }
            }
        }
        if(count==0 || count==groupSize)
            return true;
        return false;
    }
};