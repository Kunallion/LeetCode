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
    int findSum(TreeNode* root, int low, int high){
        if(root==NULL)
            return 0;
        
        if(root->val>=low && root->val<=high)
            return root->val + findSum(root->left, low, high)+findSum(root->right, low, high);
        
        return findSum(root->left, low, high) + findSum(root->right, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};