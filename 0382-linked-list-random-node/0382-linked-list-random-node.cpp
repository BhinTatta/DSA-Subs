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
private:
    ListNode* currr;
public:
    
    Solution(ListNode* head) {
        this->currr = head;
        // cout<<currr->val;
    }
    
    int getRandom() {
        int i = 0 , ans;
        ListNode* curr = currr;
        
        while(curr!=nullptr){
            i++;
            if( rand() % i == 0){
                ans = curr->val;
            }
            curr = curr->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */