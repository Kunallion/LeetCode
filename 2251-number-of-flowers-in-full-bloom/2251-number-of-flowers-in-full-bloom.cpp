class Solution {
private:
    // Function to check how many flowers have bloomed till now using Binary Search
    int total_bloomed(vector<vector<int>>& flowers, int target){
        int low = 0, high = flowers.size()-1, mid;
        int flowers_bloomed=0;
        while(low<=high){
            mid = (low + (high-low)/2);
            if(flowers[mid][0]<=target){
                flowers_bloomed = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return flowers_bloomed;
    }
    // Function to check how many flowers have stopped blooming or did not bloom till now using Binary Search
    int total_stopped_blooming(vector<vector<int>>& flowers, int target){
        int low = 0, high = flowers.size()-1, mid;
        int flowers_stopped_blooming=0;
        while(low<=high){
            mid = (low + (high-low)/2);
            if(flowers[mid][1]<target ){
                flowers_stopped_blooming = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return flowers_stopped_blooming;
    }
public:
    // Sorting the flowers array on the basis of starting time
    static bool startingTime(vector<int>& v1, vector<int>& v2){
        return v1[0]<v2[0];
    }

    // Sorting the flowers array on the basis of ending time
    static bool endingTime(vector<int>& v1, vector<int>& v2){
        return v1[1]<v2[1];
    }
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;

        // Checking How many flowers bloomed
        sort(flowers.begin(), flowers.end(), startingTime);
        for(int i=0 ; i<people.size() ; i++){
            int flowers_bloomed = total_bloomed(flowers, people[i]);
            ans.push_back(flowers_bloomed);
        }

        // Checking how many flowers stopped Blooming
        sort(flowers.begin(), flowers.end(), endingTime);
        for(int i=0 ; i<people.size() ; i++){
            int flowers_stopped_blooming = total_stopped_blooming(flowers, people[i]);

            // Updating the ans as totalBloomed - totalStoppedBlooming
            ans[i] -= flowers_stopped_blooming;
        }

        // Returning the ans vector
        return ans;
    }
};