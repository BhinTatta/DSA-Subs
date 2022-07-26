/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        TreeNode* ans;
        helper(root, p , q , ans);
        return ans;
    }
    
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q , TreeNode* &ans){
        if(!root) return false;
        bool own = false;
        if(root == p || root==q) own = true;
        
        bool left = helper(root->left , p ,q ,ans);
        bool right = helper(root->right , p ,q ,ans);
        if(own && (left|| right)) ans = root;
        if(left && right) ans = root;
        return own || (left || right);
    }
};