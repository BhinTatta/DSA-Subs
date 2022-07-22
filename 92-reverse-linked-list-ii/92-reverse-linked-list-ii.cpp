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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next || left==right) return head;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *prev = dummy, *curr = head;
        int pos = 1;
        while(pos < left){
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        ListNode *lprev = prev;
        ListNode *fwd = nullptr; 
        ListNode *mainprev = curr;
        
        prev = nullptr;
        while(pos <= right){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            pos++;
        }
        
        lprev->next = prev;
        mainprev ->next = fwd;
        
        return dummy->next;
        
    }
};