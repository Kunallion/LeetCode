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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head;
        int count = 1;
        

        if(head==NULL || head->next==NULL)
            return head;

        while(head->next!=NULL)
        {
            head = head->next;
            count++;
        }
        head->next = cur;

        k = count - (k%count);
        while (k>0)
        {
            head = head->next;
            k--;
        }

        ListNode* newNode = head->next;
        head->next = NULL;

        return newNode;

    }
};