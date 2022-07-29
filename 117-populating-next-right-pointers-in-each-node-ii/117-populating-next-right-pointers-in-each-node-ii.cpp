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
        vector<vector<Node*>> store;
        queue<Node*> q;
        q.push(root);
        bfs(store,q);
        int n = store.size();
        
        for(int i = 0 ; i < n ; i++){
            Node* to_point = NULL;
            for(int j = store[i].size()-1 ; j >=0 ; j--){
                //cout<<i<<" "<<j<<endl;
                Node* curr = store[i][j];
                curr->next = to_point;
                to_point = curr;
            }
        }
        
        return root;
    }
    
    void bfs(vector<vector<Node*>> &store , queue<Node*>q){
        if(q.empty()) return;
        //cout<<"bfs";
        vector<Node*> level;
        queue<Node*> newq;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            level.push_back(curr);
            if(curr->left) newq.push(curr->left);
            if(curr->right) newq.push(curr->right);
        }
        store.push_back(level);
        bfs(store,newq);
    }
};