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
    
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);       
    }
    
    int dfs(TreeNode* root , int large){
        if(!root) return 0;
        if(root->val >= large){
            large = max(large , root->val);
            return 1 + dfs(root->left , large) + dfs(root->right , large);
        }
        else{
            return dfs(root->left , large) + dfs(root->right , large);
        }
        return 0;
    }
};