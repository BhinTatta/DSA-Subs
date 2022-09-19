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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ans = dummy;
        ListNode* prev = dummy;
        dummy = dummy->next;
        
        while(dummy && dummy->next ){
            ListNode *one = dummy->next;
            ListNode *fwd = one->next;
            
            prev->next = one;
            one->next = dummy;
            dummy->next = fwd;
            prev = dummy;
            if(dummy) dummy = dummy->next;
        }
        
        return ans->next;
    }
};