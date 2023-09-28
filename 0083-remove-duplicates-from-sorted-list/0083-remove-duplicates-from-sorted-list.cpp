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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp = head;
        head = head->next;
        while(head!=NULL)
        {
            if(head->val==temp->val)
            {
                temp->next = head->next;
                head = temp->next;
            }
            else
            {
                temp = temp->next;
                head = head->next;
            }
        }
        head = ptr;
        return head;
    }
};