class Solution {
private:
    // Function to find distance between 2 points
    float findLength(vector<int>& x, vector<int>& y){
        return sqrt((x[0]-y[0])*(x[0]-y[0]) + ((x[1]-y[1])*(x[1]-y[1])));
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        float len;

        unordered_map<float, int> mp;
        vector<vector<int>> points;
        
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);

        // Check if all points are distinct, since square has 4 distinct points
        if(!(p1!=p2 && p1!=p3 && p1!=p4 && p2!=p3 && p2!=p4 && p3!=p4))
            return false;

        // Calculate all 12 distances and store them in hashmap
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                if(i!=j){
                    len = findLength(points[i], points[j]);
                    mp[len]++;
                }
            }
        }

        // Distinct distances should be only 2
        if(mp.size()!=2)
            return false;
        
        // One of them needs to be 8 and other 4
        for(auto it:mp){
            if(it.second==8)
                return true;
        }
        return false;

    }
};