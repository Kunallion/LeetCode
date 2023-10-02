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
    void solve(TreeNode* root, int left_or_right, int& sum)
    {
        if(root->left==NULL && root->right==NULL)
        {
            // left_or_right==0 means it is a left child
            // left_or_right==1 means it is a right child

            if(left_or_right==0)
                sum += root->val;

            return;
        }


        if(root->left)
            solve(root->left, 0, sum);
        if(root->right)
            solve(root->right, 1, sum);
        
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum=0;
        solve(root, 1, sum);

        return sum;
    }
};