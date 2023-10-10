class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        // Priority queue to sort the friends on the basis of their arrival time and also including their id
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int friend_id = 0;
        for(int i=0 ; i<times.size() ; i++){
            pq.push({times[i][0], friend_id, times[i][1]});
            friend_id++;
        }

        // This vector is initially all 0, which means all the chairs are unoccupied
        vector<int> arr(pq.size(), 0);

        while(true && !pq.empty()){
            auto it = pq.top();
            pq.pop();
            int i;
            for(i=0 ; i<arr.size() ; i++){
                if(arr[i]==0){
                    // the first unoccupied chair is occupied by the friend who comes next
                    arr[i] = it[2];
                    break;
                }
                // the occupied chairs contains the leaving time of the friend. If the friend who comes next has arrival time more than or equal to the leaving time of the person occupying the chair, then she/he occupies it
                else if(arr[i]<=it[0]){
                    arr[i] = it[2];
                    break;
                }
            }
            // if the target friend occupies a seat, then we return which seat he occupied
            if(it[1]==targetFriend){
                return i;
            }
        }
        return 0;
    }
};