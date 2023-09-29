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
    void allpaths(TreeNode* root, vector<int> temp, vector<vector<int>> &ans, int sum, int target)
    {
        sum += root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==target)
        {
            ans.push_back(temp);
            return;
        }     
        if(root->left)
            allpaths(root->left, temp, ans, sum, target);
        if(root->right)
            allpaths(root->right, temp, ans, sum, target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==NULL)
            return ans;
            
        allpaths(root, temp, ans, 0, targetSum);
        return ans;
    }
};