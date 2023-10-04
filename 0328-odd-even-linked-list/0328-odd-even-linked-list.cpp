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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* temp = head;
        ListNode* newhead = new ListNode(0);
        ListNode* temp2 = newhead;

        while(head!=NULL){

            ListNode* node = new ListNode(head->val);
            newhead->next = node;
            newhead = newhead->next;
            
            if(head->next==NULL)
                break;
            head = head->next->next;
        }

        head = temp;
        head = head->next;

        while(head!=NULL){

            ListNode* node = new ListNode(head->val);
            newhead->next = node;
            newhead = newhead->next;
            
            if(head->next==NULL)
                break;
            head = head->next->next;
        }

        return temp2->next;
    }
};