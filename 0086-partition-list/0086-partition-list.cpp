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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ptr = head;
        ListNode* firstpart = new ListNode(0, NULL);
        ListNode* secondpart = new ListNode(0, NULL);
        ListNode* ptrsecond = secondpart;
        ListNode* ptrfirst = firstpart;

        while(head!=NULL)
        {
            if((head->val) < x)
            {
                firstpart->next = head;
                firstpart = firstpart->next;
            }
            else
            {
                secondpart->next = head;
                secondpart = secondpart->next;
            }
            head = head->next;
        }
        firstpart->next = ptrsecond->next;
        secondpart->next = NULL;
        return ptrfirst->next;
    }
};