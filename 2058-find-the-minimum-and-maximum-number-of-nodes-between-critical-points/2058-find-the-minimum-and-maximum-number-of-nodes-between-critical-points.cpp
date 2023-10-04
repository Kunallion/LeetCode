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
        
        // Pushing all the elements in an array for easier access, otherwise we can directly do with the linked list also
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }

        // Initialize values
        int mini = INT_MAX;
        int maxi = -1;
        int prev = -1, FirstCriticalPoint = -1, LastCriticalPoint = -1;

        // Traversing the array
        for(int i=1 ; i<arr.size()-1 ; i++){

            // Checking for both minima and maxima condition simultaneously
            if((arr[i]<arr[i-1] && arr[i]<arr[i+1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1]))
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