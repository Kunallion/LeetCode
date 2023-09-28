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
    void levelOrderTraversal(TreeNode* root, unordered_map<int,int>& mp, int level)
    {
        if(root==NULL)
            return;
        
        mp[level] += root->val;

        levelOrderTraversal(root->left, mp, level+1);
        levelOrderTraversal(root->right, mp, level+1);

    }
public:
    int maxLevelSum(TreeNode* root) {

        unordered_map<int,int> mp;
        levelOrderTraversal(root, mp, 1);
        
        int ans=INT_MAX, maxi=INT_MIN;
        for(auto it:mp)
        {
            if(it.second>maxi)
            {
                ans = it.first;
                maxi = it.second;
            }
            else if(it.second==maxi && it.first<ans)
            {
                ans = it.first;
            }
        }
        return ans;
    }
};