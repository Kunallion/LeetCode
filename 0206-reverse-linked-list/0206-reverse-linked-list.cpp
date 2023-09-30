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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* nextnode = head;

        while(nextnode!=NULL)
        {
            nextnode = head->next;
            head->next = newhead;
            newhead = head;  
            head = nextnode;
        }
        return newhead;
    }
};