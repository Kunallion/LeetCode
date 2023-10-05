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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        int count=0, flag=0, i=0;

        // Storing nums in hashmap for easier searching of elements
        unordered_map<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]] = 1;
        }

        while(head!=NULL){

            if(mp.find(head->val)!=mp.end() && flag==0){
                count++;
                flag=1;
            }
            else if(mp.find(head->val)==mp.end() && flag==1){
                flag=0;
            }
            head = head->next;
        }
        return count;
    }
};