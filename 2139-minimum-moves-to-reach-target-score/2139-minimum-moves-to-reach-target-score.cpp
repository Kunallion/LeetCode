class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int moves=0;
        while(maxDoubles>0 && target!=0){
            if(target%2==0){
                target /= 2;
                maxDoubles--;
                moves++;
            }
            else if(target%2==1){
                moves++;
                target -= 1;
            }
        }
        moves += target-1;
        return moves;
    }
};