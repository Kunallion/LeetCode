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
// class Solution {
// private:
//     void insertRight(TreeNode* root, TreeNode* newroot)
//     {
//         if(root==NULL)
//             return;
        
//         TreeNode* nextnode = new TreeNode(root->val);
//         newroot->right = nextnode;
//         newroot = newroot->right;

//         insertRight(root->left, newroot);
//         insertLeft(root->right, newroot);
//     }
//     void insertLeft(TreeNode* root, TreeNode* newroot)
//     {
//         if(root==NULL)
//             return;
        
//         TreeNode* nextnode = new TreeNode(root->val);
//         newroot->left = nextnode;
//         newroot = newroot->left;

//         insertRight(root->left, newroot);
//         insertLeft(root->right, newroot);
//     }
// public:
//     TreeNode* invertTree(TreeNode* root) {
        
//         if(root==NULL || root->left==NULL && root->right==NULL)
//             return root;

//         TreeNode* newroot = new TreeNode(root->val);
        
//         if(root->left)
//             insertRight(root->left, newroot);
//         if(root->right)
//             insertLeft(root->right, newroot);
        
//         return newroot;
//     }
// };



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL)
            return root;

        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left, root->right);
        return root;
    }
};