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
private:
    void level_traversal(TreeNode* root, int level, map<int, vector<int>>& mp)
    {
        if(root==NULL)
            return;
        
        mp[level].push_back(root->val);

        if(root->left)
            level_traversal(root->left, level+1, mp);
        if(root->right)
            level_traversal(root->right, level+1, mp);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        
        level_traversal(root, 0, mp);
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};