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
    bool solve(TreeNode* root, int level, unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return true;
        
        if(mp.find(level)==mp.end())
            if((level%2==0 && root->val%2==1) || (level%2==1 && root->val%2==0))
                mp[level] = root->val;
            else
                return false;
        
        else if((level%2==0 && root->val%2==1 && root->val>mp[level]) || (level%2==1 && root->val%2==0 && root->val<mp[level]))
                mp[level] = root->val;
        else
            return false;
        
        return solve(root->left, level+1, mp) && solve(root->right, level+1, mp);
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        
        unordered_map<int,int> mp;
        return solve(root, 0, mp);
    }
};