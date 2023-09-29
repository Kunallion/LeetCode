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
    bool checkSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
            return true;
    
        if(root==NULL || subRoot==NULL)
            return false;

        if(root->val==subRoot->val)
            return checkSameTree(root->left, subRoot->left) && checkSameTree(root->right, subRoot->right);
        return false;
    }

    bool solve(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
            return true;
        
        if(root==NULL || subRoot==NULL)
            return false;
        
        if(root->val==subRoot->val)
        {
            if(checkSameTree(root, subRoot))
                return true;
        }

        return solve(root->left, subRoot) || solve(root->right, subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return solve(root, subRoot);
    }
};