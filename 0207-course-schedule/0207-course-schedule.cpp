class Solution {
public:
    void make_adj_list(unordered_map<int,vector<int>> &mp, vector<vector<int>> &prerequisites)
    {
        for(int i=0 ; i<prerequisites.size() ; i++)
        {
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        make_adj_list(mp, prerequisites);

        vector<int> indegree(numCourses);
        for(auto it:mp)
        {
            for(auto jt:it.second)
                indegree[jt]++;
        }
        
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        int count=0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            count++;
            for(auto it:mp[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(count==numCourses)
            return true;
        return false;
    }
};