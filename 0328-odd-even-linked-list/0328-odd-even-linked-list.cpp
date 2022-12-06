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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* maineven = head->next;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddnext;
        ListNode* evennext;
        
        while(even && even->next){
            oddnext = even->next;
            evennext = oddnext->next;
            odd->next = oddnext;
            odd = odd->next;
            even->next = evennext;
            even = even->next;
        }
        odd->next = maineven;
        return head;
    }
};