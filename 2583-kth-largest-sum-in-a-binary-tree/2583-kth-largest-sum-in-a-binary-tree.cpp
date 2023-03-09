/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue<long long int> pq;
    queue<TreeNode*> q;
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;
        q.push(root);
     
        summer();
        k--;
        while(!pq.empty() && k-->0){
            pq.pop();
        }
        return pq.empty()==true ? -1 : pq.top();
    }
    
    void summer(){
        int len = q.size();
        if(len==0) return;
        long long int ans = 0;
        
        while(len-->0){
            TreeNode* curr = q.front();
            q.pop();
            ans += curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
        pq.push(ans);
        summer();
    }
};