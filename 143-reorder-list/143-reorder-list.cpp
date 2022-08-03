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
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next) return;
        vector<ListNode*> arr;
        ListNode* curr = head;
        
        while(curr!=nullptr){
            arr.push_back(curr);
            curr = curr->next;
        }
        
        int i = 0 , j = arr.size()-1;
        int last;
        while(i<j){
            arr[i]->next = arr[j];
            // cout<<arr[i]->val <<"  -> "<<arr[j]->val<<endl;
            // cout<<"i & j = "<<i<<" "<<j<<endl;
            i++;
            last = j;
            if(j-i>0){
                arr[j]->next = arr[i];
                last = i;
                // cout<<arr[j]->val <<"  -> "<<arr[i]->val<<endl;
                // cout<<"i & j = "<<i<<" "<<j<<endl;
                j--;
    
            }
        }
        arr[last]->next = nullptr;
    }
};