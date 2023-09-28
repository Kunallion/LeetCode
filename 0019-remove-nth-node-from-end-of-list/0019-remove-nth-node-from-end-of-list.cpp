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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        if(count==n)
        {
            return head->next;
        }
        count = count-n-1;
        temp = head;
        while(count--)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};