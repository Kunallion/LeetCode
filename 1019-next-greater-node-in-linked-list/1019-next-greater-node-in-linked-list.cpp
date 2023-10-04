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
    vector<int> nextLargerNodes(ListNode* head) {
        
        // Finding the length of Linked List
        int count=0;
        ListNode* temp = head;
        while(head!=NULL){
            count++;
            head = head->next;
        }

        int index=0;
        head = temp;

        // Intitializing a vector with all values 0 and length equal to the length of Linked List
        vector<int> ans(count, 0);
        stack<pair<int,int>> st;

        // Main Operations
        while(head!=NULL){

            // If stack is empty, then push the first element with it's index
            if(st.empty())
                st.push({head->val, index});
            
            else{

                // If the present head val is greater than the top of stack, then pop the stack and update the value in the ans array.
                while(!st.empty() && head->val>st.top().first){
                    ans[st.top().second] = head->val;
                    st.pop();
                }
                st.push({head->val, index});
            }
            index++;
            head = head->next;
        }

        // Return ans
        return ans; 
    }
};