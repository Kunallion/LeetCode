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

        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* newhead = NULL;
        ListNode* nextnode = head;

        while(head!=NULL){
            nextnode = head->next;
            head->next = newhead;
            newhead = head;
            head = nextnode;
        }
        return newhead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);

        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        int sum=0, carry=0;

        while(l1!=NULL || l2!=NULL || carry!=0){

            sum = 0;
            if(l1!=NULL){
                sum = l1->val;
                l1 = l1->next;
            }

            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            if(carry>0)
                sum += carry;
            
            carry = sum/10;
            sum = sum%10;

            ListNode* nextNode = new ListNode(sum);
            head->next = nextNode;
            head = head->next;
        }

        head = temp->next;
        head = reverseLinkedList(head);
        return head;
    }
};