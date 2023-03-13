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
    bool isSymmetric(TreeNode* root) {
        return helper(root->left , root->right);
    }
    
    bool helper(TreeNode* a , TreeNode* b){
        if(!a && !b) return true;
        if( (!a && b) || (a && !b) || (a->val != b->val)  ) return false;
        return helper(a->left , b->right) && helper(a->right , b->left);
    }
};