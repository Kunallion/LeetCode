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

    int countNodes(TreeNode* root) {

        if(root==NULL)
            return 0;
        
        int left_height=0, right_height=0;

        TreeNode* l = root;
        TreeNode* r = root;

        while(l!=NULL)
        {
            left_height++;
            l = l->left;
        }
        while(r!=NULL)
        {
            right_height++;
            r = r->right;
        }

        if(left_height==right_height)
            return pow(2, left_height)-1;
        
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};