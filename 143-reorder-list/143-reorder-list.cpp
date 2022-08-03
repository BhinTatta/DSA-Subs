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
        int size = 0;
        while(curr!=nullptr){
            arr.push_back(curr);
            curr = curr->next;
            size++;
        }
        
        int i = 0 , j = size-1;
        int last;  //keeps track of last node, as it has to be pointed to null;
        while(i<j){
            arr[i]->next = arr[j];
            i++;
            last = j;
            if(j-i>0){
                arr[j]->next = arr[i];
                last = i;
                j--;
            }
        }
        arr[last]->next = nullptr;
    }
};