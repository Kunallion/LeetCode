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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp = new ListNode(0, NULL);
        temp->next = head;

        // Counting Frequency of each element
        while(head!=NULL)
        {
            mp[head->val]++;
            head = head->next;
        }
        head = temp->next;

        ListNode* temp2 = new ListNode(0, NULL);
        temp2->next = head;
        temp = temp2;

        while(head!=NULL)
        {
            if(mp[head->val]>1)
            {
                int num = head->val;
                while(head!=NULL && head->val==num)
                {
                    head = head->next;
                }
                temp2->next = head;
            }
            else
            {
                temp2 = head;
                head = head->next;
            }
        }
        return temp->next;
    }
};