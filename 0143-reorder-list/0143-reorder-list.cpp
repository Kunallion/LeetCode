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
    // Reversing the LinkedList
    ListNode* reverseLinkedList(ListNode* head){

        ListNode* newhead = NULL;
        ListNode* nextnode = NULL;

        while(head!=NULL){
            
            nextnode = head->next;
            head->next = newhead;
            newhead = head;
            head = nextnode;
        }
        return newhead;
    }
public:
    void reorderList(ListNode* head) {
        
        if(head->next==NULL)
            return;

        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Finding Middle of Linked List
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Creating the second LinkedList which will have elements after the middle of the original linkedList
        ListNode* head2 = slow->next; 
        head2 = reverseLinkedList(head2);

        // Updating NULL value at the end of middle value
        while(temp!=slow){
                temp = temp->next;
        }
        temp->next = NULL;

        // Inserting the second list elements alternatively in first list
        while(head2!=NULL){
            
            ListNode* newNode = new ListNode(head2->val);
            head2 = head2->next;

            newNode->next = head->next;
            head->next = newNode;
            
            head = newNode->next;
        }
    }
};
