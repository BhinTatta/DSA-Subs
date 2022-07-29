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
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        bfs(q);        
        return root;
    }
    
    void bfs(queue<Node*>q){
        if(q.empty()) return;
        queue<Node*> newq;
        Node* to_point = NULL;
        while(!q.empty()){
            Node* curr = q.front();
            curr->next = to_point;
            to_point = curr;
            q.pop();
            if(curr->right) newq.push(curr->right);
            if(curr->left) newq.push(curr->left);
        }
        bfs(newq);
    }
};