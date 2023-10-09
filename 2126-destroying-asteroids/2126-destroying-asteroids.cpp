class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        // Sort The asteroids weights in increasing order
        sort(asteroids.begin(), asteroids.end());
        int i=0;
        while(i<asteroids.size() && mass>=asteroids[i]){
            // Keep adding the weight of asteroids if they cannot destroy the planet
            mass += asteroids[i];
            i++;

            // max mass of any asteroid is 10^5 given in question. So if our mass of planet exceeds 10^5, then it can definately destroy all the asteroids, hence no need to check further, return true
            if(mass>=100001)
                return true;
        }

        // If we destroy all the asteroids, then return true
        if(i==asteroids.size())
            return true;
        return false;
    }
};