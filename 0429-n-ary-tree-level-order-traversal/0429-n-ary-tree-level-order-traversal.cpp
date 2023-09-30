/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void levelOrderTraversal(Node* root, map<int, vector<int>>& mp, int level)
    {
        if(root==NULL)
            return;
        
        mp[level].push_back(root->val);

        for(auto it: root->children)
            levelOrderTraversal(it, mp, level+1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        map<int, vector<int>> mp;
        vector<vector<int>> ans;

        levelOrderTraversal(root, mp, 0);

        for(auto it:mp){
            ans.push_back(it.second);
        } 
        return ans;
    }
};