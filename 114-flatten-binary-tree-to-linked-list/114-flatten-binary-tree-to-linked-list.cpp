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
    queue<TreeNode*> q;
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
        TreeNode* temp = new TreeNode();
        TreeNode* hehe = temp;
        
        while(!q.empty()){
            temp->left = nullptr;
            temp->right = q.front();
            temp = temp->right;
            q.pop();
        }
        root = hehe;
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        
        q.push(root);
        dfs(root->left);
        dfs(root->right);
    }
};