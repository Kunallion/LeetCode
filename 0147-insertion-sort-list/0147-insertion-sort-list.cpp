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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newhead = new ListNode(-INT_MAX);
        newhead->next = NULL;
        ListNode* temp = newhead;

        while(head!=NULL)
        {
            ListNode* nextnode = new ListNode(head->val);
            ListNode* prev = newhead;
            head = head->next;
            newhead = newhead->next;
            while(newhead!=NULL)
            {
                if(nextnode->val<=newhead->val)
                {
                    prev->next = nextnode;
                    prev = prev->next;
                    prev->next = newhead;
                    break;
                }
                prev = newhead;
                newhead = newhead->next;
            }
            if(newhead==NULL)
            {
                prev->next = nextnode;
            }
            newhead = temp;
        }
        return temp->next;
    }
};