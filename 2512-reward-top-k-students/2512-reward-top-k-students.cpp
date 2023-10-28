class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        vector<int> ans;
        map<int, vector<int>, greater<int>> points;
        unordered_map<string, int> mp;

        // Storing positive words in map along with value +3
        for(int i=0 ; i<positive_feedback.size() ; i++){
            mp[positive_feedback[i]] = 3;
        }

        // Storing negative words in map along with value -1
        for(int i=0 ; i<negative_feedback.size() ; i++){
            mp[negative_feedback[i]] = -1;
        }


        // Calculating score earned by each student
        for(int i=0 ; i<report.size() ; i++){
            string temp="";
            int score = 0;
            for(int j=0 ; j<report[i].size() ; j++){
                if(report[i][j]==' '){
                    if(mp.find(temp)!=mp.end()){
                        score += mp[temp];
                    }
                    temp = "";
                }
                else{
                    temp += report[i][j];
                }
            }
            if(mp.find(temp)!=mp.end()){
                score += mp[temp];
            }

            // Pushing the student id for the score obtained in points map
            points[score].push_back(student_id[i]);
        }


        // Points map is sorted in decreasing order
        for(auto it:points){

            // Student ids with same marks are sorted in increasing order
            sort(it.second.begin(), it.second.end());
            for(int i=0 ; i<it.second.size() ; i++){
                ans.push_back(it.second[i]);

                // When size of ans array becomes k, then return array.
                if(ans.size()==k)
                    return ans;
            }
        }
        return ans;
    }
};