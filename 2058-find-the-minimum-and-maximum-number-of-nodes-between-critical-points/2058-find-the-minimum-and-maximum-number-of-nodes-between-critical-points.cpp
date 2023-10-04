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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(head->next->next==NULL)
            return {-1,-1};

        // Initialize values
        int mini = INT_MAX;
        int maxi = -1;
        int prev = -1, FirstCriticalPoint = -1, LastCriticalPoint = -1;

        // Traversing the array
        int prevNodeVal = head->val;
        int i=0;
        head = head->next;
        while(head->next!=NULL){

            // Checking for both minima and maxima condition simultaneously
            if((head->val<prevNodeVal && head->val<head->next->val) || (head->val>prevNodeVal && head->val>head->next->val))
            {
                if(FirstCriticalPoint == -1){
                    FirstCriticalPoint = i;
                }

                // Update the current maxima/minima index
                LastCriticalPoint = i;
                
                if(prev==-1){
                    prev = i;
                }
                else{
                    mini = min(mini, i-prev);
                    prev = i;
                }
            }
            i++;
            prevNodeVal = head->val;
            head = head->next;
        }

        // Calculate max distance 
        maxi = LastCriticalPoint-FirstCriticalPoint;

        // Some checks
        if(maxi==0)
            maxi = -1;
        if(mini==INT_MAX)
            mini = -1;

        // Return ans
        return {mini, maxi}; 
    }
};