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
    unordered_map<TreeNode* , int> mp;
    int rob(TreeNode* root) {
        return helper(root);
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        if(mp.find(root)!=mp.end()) return mp[root];
        
        int pick = root->val , dont = 0;
        
        dont = helper(root->left) + helper(root->right);
        
        if(root->left) pick += helper(root->left->left) + helper(root->left->right);
        if(root->right) pick += helper(root->right->left) + helper(root->right->right);
        
        return mp[root] =  max(pick , dont);
        
        
    }
};