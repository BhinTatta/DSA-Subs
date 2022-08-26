/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        helper(q);
        return root;
    }
    
    void helper(queue<Node*> q){
        if(q.empty()) return;
        queue<Node*> newq;
        Node* prev = nullptr;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            curr->next = prev;
            prev = curr;
            if(curr->right != nullptr) newq.push(curr->right);
            if(curr->left != nullptr) newq.push(curr->left);
        }
        helper(newq);
    }
    
    
};



























