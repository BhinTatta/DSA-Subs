/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size-->0){
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                for(auto child : curr->children){
                    q.push(child);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
















