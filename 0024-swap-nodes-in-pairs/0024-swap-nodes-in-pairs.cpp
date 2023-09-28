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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* ptr = head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;

        while(temp2!=NULL)
        {
            swap(temp1->val, temp2->val);
            temp1 = temp1->next->next;
            if(temp1==NULL || temp1->next==NULL)
                break;
            temp2 = temp2->next->next;
        }
        head = ptr;
        return ptr;
    }
};