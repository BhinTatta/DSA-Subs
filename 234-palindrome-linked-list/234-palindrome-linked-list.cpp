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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* slow = temp;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = reverse(slow);
        
        while(head!=nullptr){
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};