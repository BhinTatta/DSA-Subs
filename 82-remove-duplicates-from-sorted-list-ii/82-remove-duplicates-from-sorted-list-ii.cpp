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
        
        while(curr && curr->next){
            ListNode* temp = curr->next;
            if(temp->val != curr->val){
                prev = curr;
                curr = temp;
            }
            else{
                while(temp && curr->val == temp->val){
                    curr = curr->next;
                    temp = temp->next;
                }
                prev->next = temp;
                curr = temp;
            }
        }
        
        return dummy->next;
    }
};