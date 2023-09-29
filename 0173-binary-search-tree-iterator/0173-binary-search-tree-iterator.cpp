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
class BSTIterator {
public:
    void inorder(TreeNode* root, vector<int>& arr)
    {
        if(root->left)
            inorder(root->left, arr);
        arr.push_back(root->val);
        if(root->right)
            inorder(root->right, arr);
    }

    vector<int> arr;
    int i=0;
    BSTIterator(TreeNode* root) {
        inorder(root, arr);
    }
    
    int next() {
        i++;
        return arr[i-1];
    }
    
    bool hasNext() {
        if(i<arr.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */