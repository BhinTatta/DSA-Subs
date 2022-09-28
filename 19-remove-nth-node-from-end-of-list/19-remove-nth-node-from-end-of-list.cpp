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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* ans = dummy;
        ListNode* temp = head;
        int i = 0;
        while(temp){
            i++;
            temp = temp->next;
            if(i>n){
                dummy = dummy->next;
            }
        }
        if(!dummy->next) return ans->next;
        
        temp = dummy->next->next;
        dummy->next = temp;
        return ans->next;
    }
};