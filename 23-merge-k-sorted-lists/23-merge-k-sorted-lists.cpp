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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int , vector<ListNode*>> mp;
        int n = lists.size();
        for(auto it : lists){
            ListNode* temp = it;
            while(temp!=nullptr){
                mp[temp->val].push_back(temp);
                temp=temp->next;
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        
        for(auto it : mp){
            for(ListNode* node : it.second){
                dummy->next = node;
                dummy = dummy->next;
            }
        }
        return head->next;
    }
};












