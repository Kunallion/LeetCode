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
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int leftsum = sum(root->left);
        int rightsum = sum(root->right);

        return root->val + leftsum + rightsum;
    }
    void traverse(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        traverse(root->left);
        traverse(root->right);

        if(sum(root->left)==0)
            root->left = NULL;
        if(sum(root->right)==0)
            root->right = NULL;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        traverse(root);
        if(root->val==0 && root->left==NULL && root->right==NULL)
            return NULL;
        return root;
    }
};