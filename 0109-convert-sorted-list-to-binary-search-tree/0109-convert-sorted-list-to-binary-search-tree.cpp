/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* makeBST(vector<int>& arr, int low, int high)
    {
        if(low>high)
            return NULL;
        
        int mid = (low+(high-low)/2);
        TreeNode* root = new TreeNode(0);
        root->val = arr[mid];

        root->left = makeBST(arr, low, mid-1);
        root->right = makeBST(arr, mid+1, high);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }

        return makeBST(arr, 0, arr.size()-1);
    }
};