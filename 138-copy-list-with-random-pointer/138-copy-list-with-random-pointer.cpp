/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* dummy = new Node(0);
        
        Node* newhead = dummy;
        Node* prevhead = head;
        
        unordered_map<Node*,int> main;
        unordered_map<int,Node*> add;
        int i = 0;
        //List created and address created
        while(head!=nullptr){
            Node* temp = new Node(head->val);
            main[head] = i;
            add[i] = temp;
            dummy->next = temp;
            dummy = dummy->next;
            head = head->next;
            i++;
        }
        
        i = 0;
        head = prevhead;
        dummy = newhead->next;
        
        while(head!=nullptr){
            if(head->random!=nullptr){
                int linknode = main[head->random];
                dummy->random = add[linknode];
                //cout<<head->random<<"  "<<dummy->random->val<<endl;
            }
            head = head->next;
            dummy = dummy->next;
        }
        
        return newhead->next;
    }
};













