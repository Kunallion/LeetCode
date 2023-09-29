/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         unordered_map<int, vector<Node*>> mp;

//         if(root==NULL)
//             return root;
        
//         queue<pair<Node*, int>> q;
//         q.push({root, 0});

//         while(!q.empty())
//         {
//             auto it = q.front();
//             q.pop();
//             Node* node = it.first;
//             int line = it.second;

//             mp[line].push_back(node);

//             if(node->left)
//                 q.push({node->left, line+1});
//             if(node->right)
//                 q.push({node->right, line+1});
//         }

//         for(auto it:mp)
//         {
//             for(int i=0 ; i<it.second.size()-1 ; i++)
//             {
//                 it.second[i]->next = it.second[i+1];
//             }
//         }
//         return root;
//     }
// };




class Solution {
private:
    void solve(Node* root, int level, unordered_map<int,vector <Node*>>& mp)
    {
        if(root==NULL)
            return;
        
        mp[level].push_back(root);

        if(root->left)
            solve(root->left, level+1, mp);
        if(root->right)
            solve(root->right, level+1, mp);
    }
public:
    Node* connect(Node* root) {
        unordered_map<int, vector<Node*>> mp;
        
        solve(root, 0, mp);

        for(auto it:mp)
        {
            for(int i=0 ; i<it.second.size()-1 ; i++)
            {
                it.second[i]->next = it.second[i+1];
            }
        }
        return root;
    }
};