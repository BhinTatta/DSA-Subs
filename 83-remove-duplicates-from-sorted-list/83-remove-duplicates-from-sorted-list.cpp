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
        if(!head || !head->next) return head;
        ListNode* dummy  = new ListNode(-101 , head);
        
        ListNode *prev = dummy , *curr = head;
        
        while(curr){
            if(curr->val != prev->val){
                prev = curr;
                curr = curr->next;
            }
            else{
                while(curr && curr->val == prev->val){
                    curr = curr->next;
                }
                prev->next = curr;
            }
        }
        
        return dummy->next;
    }
};