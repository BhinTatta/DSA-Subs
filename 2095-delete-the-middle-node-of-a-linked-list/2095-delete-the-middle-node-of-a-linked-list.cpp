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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode *slow = dummy , *fast = dummy;
        bool flag = false;
        while(fast && fast->next){
            if(flag) slow = slow->next;
            flag = true;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        
        if(fast==nullptr){
            slow->next = slow->next->next;
        }
        else{
            slow = slow->next;
            slow->next = slow->next->next;
        }
        return dummy->next;

    }
};