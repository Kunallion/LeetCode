/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        while(temp!=NULL)
        {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }

        Node* itr = head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL)
            {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        Node* dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node* fast;
        while(itr!=NULL)
        {
            temp->next = itr->next;
            fast = itr->next->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};