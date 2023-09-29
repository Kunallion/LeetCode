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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        int i, j;
        
        if(head==NULL || head->next==NULL)
            return head;
        
        while(head!=NULL)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        sort(arr.begin(), arr.end());

        ListNode* newhead = new ListNode(arr[0]);
        ListNode* ptr = newhead;

        for(int i=1 ; i<arr.size() ; i++)
        {
            ListNode* nextnode = new ListNode(arr[i]);
            newhead->next = nextnode;
            newhead = newhead->next;
        }
        return ptr;
    }
};