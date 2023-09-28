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
    void traverse(TreeNode* root, int level, unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return;
        
        if(mp.find(level)==mp.end())
            mp[level] = root->val;
        
        traverse(root->left, level+1, mp);
        traverse(root->right, level+1, mp);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        
        unordered_map<int,int> mp;
        int level = 0;
        traverse(root, level, mp);
        int ans_level=0;
        for(auto it:mp)
        {
            if(it.first>ans_level)
                ans_level = it.first;
        }

        return mp[ans_level];
    }
};