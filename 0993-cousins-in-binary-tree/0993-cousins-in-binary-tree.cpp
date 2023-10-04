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
    void findDepth(TreeNode* root, int target, int level, int prev, int& parent, int& depth){

        if(root==NULL)
            return;

        if(root->val==target){
            depth = level;
            parent = prev;
            return;
        }

        level++;

        findDepth(root->left, target, level, root->val, parent, depth);
        findDepth(root->right, target, level, root->val, parent, depth);
        
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        int depthX=0, parentX;
        findDepth(root, x, 0, 0, parentX, depthX);

        int depthY=0, parentY;
        findDepth(root, y, 0, 0, parentY, depthY);

        if(depthX==depthY && parentX!=parentY)
            return true;
        
        return false;
    }
};