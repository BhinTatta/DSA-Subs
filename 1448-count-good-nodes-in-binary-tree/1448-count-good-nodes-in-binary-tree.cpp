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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return ans;
    }
    
    void dfs(TreeNode* root , int large){
        if(!root) return;
        if(root->val >= large) ans++;
        
        dfs(root->left , max(large , root->val));
        dfs(root->right , max(large , root->val));
    }
};