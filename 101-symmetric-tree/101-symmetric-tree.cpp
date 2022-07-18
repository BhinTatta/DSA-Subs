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
    
    bool helper(TreeNode* lroot , TreeNode* rroot){
        if(!lroot && !rroot) return true;
        if( (rroot && !lroot) || (lroot &&!rroot)) return false;
        
        if ( rroot->val != lroot->val) return false;
        
        bool x = helper( lroot->left , rroot->right);
        bool y = helper( lroot->right , rroot->left);
        
        return x && y;
    }
};