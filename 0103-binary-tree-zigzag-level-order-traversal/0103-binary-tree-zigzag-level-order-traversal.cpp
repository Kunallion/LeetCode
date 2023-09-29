/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;

        if(root==NULL)
            return ans;

        map<int,vector<int>> mp;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int level = it.second;

            mp[level].push_back(node->val);
            if(node->left)
                q.push({node->left, level+1});
            if(node->right)
                q.push({node->right, level+1});
        }
        int j=0;
        for(auto it:mp)
        {
            if(j%2==0)
            {
                for(int i=0 ; i<it.second.size() ; i++)
                {
                    temp.push_back(it.second[i]);
                }
            }
            else
            {
                for(int i=it.second.size()-1 ; i>=0 ; i--)
                {
                    temp.push_back(it.second[i]);
                }
            }
            ans.push_back(temp);
            temp.clear();
            j++;
        }
        return ans;
    }
};