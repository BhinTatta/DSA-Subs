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
    bool hasPathSum(TreeNode* root, int k) {
        if(!root) return false;
        return helper(root , k - root->val);
    }
    
    bool helper(TreeNode* root , int k){
        if(!root->left && !root->right){
            return k==0;
        }
        bool a , b;
        if(root->left) a = helper(root->left , k - root->left->val);
        if(root->right) b = helper(root->right , k - root->right->val);
        
        return a || b;
    }
};