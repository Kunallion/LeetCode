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
    void solve(TreeNode* root, int num, int& ans)
    {
        num = num*10 + root->val;

        // Base Case
        if(root->left==NULL && root->right==NULL)
        {
            ans += num;
            return;
        }

        if(root->left)
            solve(root->left, num, ans);
        if(root->right)
            solve(root->right, num, ans);

        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        
        int ans=0;
        solve(root, 0, ans);
        
        return ans;
    }
};