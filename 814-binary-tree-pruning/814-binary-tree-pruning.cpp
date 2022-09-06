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
    TreeNode* pruneTree(TreeNode* root) {
        bool node = helper(root);
        if(!node) return nullptr;
        return root;
    }
    
    bool helper(TreeNode* root){
        if(!root) return false;
        if(!root->left && !root->right){
            return root->val;
        }
        
        bool l = false , r = false;
        l = helper(root->left);
        r = helper(root->right);
        
        if(!l) root->left = nullptr;
        if(!r) root->right = nullptr;
        
        return root->val || (l||r);
    }
};











