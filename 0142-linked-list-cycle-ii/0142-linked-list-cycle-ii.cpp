/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *dummy = new ListNode(0,head);
        ListNode *slow = dummy , *fast = dummy;
        
        while( (fast)  && (fast!=slow || slow==dummy) ){
            fast = fast->next;
            if(!fast || !fast->next ){
                return NULL;
            }
            else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        if(!fast || !fast->next){
            return NULL;
        }
        
        slow = dummy;
        
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};