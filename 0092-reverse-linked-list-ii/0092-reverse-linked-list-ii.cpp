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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr = new ListNode(0, NULL);
        ListNode* leftnode_prev = ptr;
        ptr->next = head;
        
        left -= 1;
        int count = left;
        while(count>0)
        {
            leftnode_prev = head;
            head = head->next;
            count--;
        }
        ListNode* leftnode = head;
        ListNode* nextnode = head;
        ListNode* prev = new ListNode(0, NULL);

        count = right-left;
        while(count>0)
        {
            nextnode = head->next;
            head->next = prev;
            prev = head;
            head = nextnode;
            count--;
        }
        leftnode_prev->next = prev;
        leftnode->next = head;
        return ptr->next;
    }
};