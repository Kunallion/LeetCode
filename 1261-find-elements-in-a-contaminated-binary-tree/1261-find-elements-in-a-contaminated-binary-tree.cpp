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
class FindElements {
private:
    void populateTree(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL) 
            return;
        
        if(root->left)
        {
            root->left->val = 2*root->val+1;
            populateTree(root->left);
        }
        if(root->right)
        {
            root->right->val = 2*root->val+2;
            populateTree(root->right);
        }
    }
    bool findTarget(TreeNode* root, int target)
    {
        if(root==NULL)
            return false;
        
        if(root->val==target)
            return true;
        
        return findTarget(root->left, target) || findTarget(root->right, target);
    }
public:
    TreeNode* newroot;
    FindElements(TreeNode* root) {
        newroot = root;
        newroot->val = 0;

        populateTree(newroot);
    }
    
    bool find(int target) {
        return findTarget(newroot, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */