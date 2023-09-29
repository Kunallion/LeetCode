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
    void solve(TreeNode* root, int level, map<int,int>& mp)
    {
        if(root==NULL)
            return;
        
        if(mp.find(level)==mp.end())
            mp[level] = root->val;

        if(root->right)
            solve(root->right, level+1, mp);
        if(root->left)
            solve(root->left, level+1, mp);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {

        map<int, int> mp;
        vector<int> ans;

        solve(root, 0, mp);

        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};