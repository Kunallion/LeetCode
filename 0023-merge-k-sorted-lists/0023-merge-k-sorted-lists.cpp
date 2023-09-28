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

    void merge(vector<ListNode*>& lists)
    {
        ListNode* head1 = lists[0];
        ListNode* head2 = lists[1];
        ListNode* ptr = head1;

        if(head1==NULL && head2==NULL)
        {
            lists.erase(lists.begin()+0);
            lists[0] = NULL;
            return;
        }
        if(head1==NULL)
        {
            lists.erase(lists.begin()+0);
            return;
        }
        if(head2==NULL)
        {
            lists.erase(lists.begin()+1);
            return;
        }
        if(head1->val>head2->val)
        {
            ptr = head2;
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
        }
        ListNode* curr = ptr;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val > head2->val)
            {
                curr->next = head2;
                head2 = head2->next;
            }
            else
            {
                curr->next = head1;
                head1=head1->next;
            }
            curr = curr->next;
        }
        if(head1!=NULL)
        {
            curr->next = head1;
        }
        else
        {
            curr->next = head2;
        }
        lists.erase(lists.begin()+0);
        lists[0] = ptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while(lists.size()>1)
        {
            merge(lists);
        }
        if(lists.size()==0)
            return NULL;
        return lists[0];
    }
};