class Solution {
public:
    void adjlist(unordered_map<int, vector<int>> &mp, vector<vector<int>> &prerequisites)
    {
        for(int i=0 ; i<prerequisites.size() ; i++)
        {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        adjlist(mp, prerequisites);

        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        int count=0;

        for(int i=0 ; i<prerequisites.size() ; i++)
        {
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i=0 ; i<indegree.size() ; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);
            count++;
            for(auto it:mp[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(count==numCourses)
            return ans;
        return {};
    }
};