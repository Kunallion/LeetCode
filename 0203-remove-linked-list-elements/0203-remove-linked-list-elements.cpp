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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr = head;
        if(head==NULL)
            return head;
        while(head->next!=NULL)
        {
            if(head->next->val==val)
            {
                head->next = head->next->next;
            }
            else
                head = head->next;
            if(head==NULL)
                break;
        }
        head = ptr;
        if(head->val==val)
        {
            head = head->next;
        }
        return head;
    }
};