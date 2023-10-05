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
private:
    ListNode* reverseLinkedList(ListNode* head){
        
        ListNode* newhead = NULL;
        ListNode* nextNode = NULL;

        while(head!=NULL){
            nextNode = head->next;
            head->next = newhead;
            newhead = head;
            head = nextNode;
        }
        return newhead;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        
        head = reverseLinkedList(head);

        ListNode* temp = head;
        int prod, carry=0;

        while(head!=NULL){

            prod = (2*head->val+carry);
            carry = (prod)/10;
            head->val = prod%10;

            if(head->next==NULL)
                break;
            head = head->next;
        }

        if(carry>0){
            ListNode* newnode = new ListNode(carry);
            head->next = newnode;
        }

        head = temp;
        head = reverseLinkedList(head);

        return head;
    }
};