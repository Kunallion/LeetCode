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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* temp = head;
        while(head->next!=NULL){

            int num1 = head->val;
            int num2 = head->next->val;

            ListNode* gcd = new ListNode(__gcd(num1, num2));

            gcd->next = head->next;
            head->next = gcd;

            head = head->next->next;
        }
        return temp;
    }
};