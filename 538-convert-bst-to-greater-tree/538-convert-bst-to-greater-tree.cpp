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
    TreeNode* convertBST(TreeNode* root) {
        int carry = 0;
        helper(root , carry);
        return root;
    }
    
    void helper(TreeNode* root , int &carry){
        if(!root) return;
        helper(root->right , carry);
        root->val += carry;
        carry = root->val;
        helper(root->left , carry);
    }
};















