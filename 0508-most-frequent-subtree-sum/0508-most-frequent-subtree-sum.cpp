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
    int subTreeSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return root->val+subTreeSum(root->left)+subTreeSum(root->right);
    }
    void traverseTree(TreeNode* root, unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return;
        
        mp[subTreeSum(root)]++;

        traverseTree(root->left, mp);
        traverseTree(root->right, mp);
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int> mp;
        vector<int> ans;

        traverseTree(root, mp);

        int maxi=0;
        for(auto it:mp)
            maxi = max(maxi, it.second);
        
        for(auto it:mp)
            if(it.second==maxi)
                ans.push_back(it.first);
        
        return ans;
    }
};