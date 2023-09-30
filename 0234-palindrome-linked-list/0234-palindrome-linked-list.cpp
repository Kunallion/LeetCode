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
    bool isPalindrome(ListNode* head) {
        ListNode* ptr = head;
        ListNode* newhead = NULL;
        ListNode* nextnode = head;
        int count=0, odd=0;

        while(head!=NULL)
        {
            count++;
            head = head->next;
        }
        if(count%2==1)
            odd = 1;
        
        count = count/2;
        head = ptr;
        while(count--)
        {
            nextnode = head->next;
            head->next = newhead;
            newhead = head;
            head = nextnode;
        }
        if(odd==1)
        {
            head = head->next;
        }
        while(newhead!=NULL and head!=NULL)
        {
            if(newhead->val!=head->val)
                return false;
            
            newhead = newhead->next;
            head = head->next;
        }
        return true;
    }
};