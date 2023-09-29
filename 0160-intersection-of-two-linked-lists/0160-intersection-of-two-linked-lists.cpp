/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* oneA = headA;
        ListNode* twoB = headB;

        while(oneA!=twoB)
        {
            if(oneA!=NULL)
                oneA = oneA->next;
            else
                oneA = headB;
            
            if(twoB!=NULL)
                twoB = twoB->next;
            else
                twoB = headA;
        }
        return oneA;
    }
};