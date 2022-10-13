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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0 , head);
        ListNode* beg = dummy;
        for(int i = 0 ; i < k ; i++){
            beg = beg->next;
        }
        
        ListNode* back = dummy;
        ListNode* front = dummy;
        int c = 0;
        while(front){
            c++;
            front = front->next;
            if(c>k) back = back->next;
        }
        
        int x = beg->val;
        beg->val = back->val;
        back->val = x;
        return head;
    }
};