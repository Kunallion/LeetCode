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
    bool pathsum(TreeNode* root, int sum, int target)
    {
        if(root==NULL)
            return false;
        sum += root->val;
        if(sum==target && root->left==NULL && root->right==NULL)
            return true;
        
        // if(root->left && root->right)
            return (pathsum(root->left, sum, target) || pathsum(root->right, sum, target));
        // if(root->left)
        //     return pathsum(root->left, sum, target);
        // if(root->right)
        //     return pathsum(root->right, sum, target);
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        
        int sum=0;
        return pathsum(root, sum, targetSum);
    }
};