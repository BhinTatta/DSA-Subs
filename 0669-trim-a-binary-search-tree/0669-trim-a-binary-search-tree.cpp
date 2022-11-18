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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        if(root->val < low) return trimBST(root->right , low , high);
        if(root->val > high) return trimBST(root->left , low , high);
        
        helper(root->left , low , high , root);
        helper(root->right , low , high , root);
        return root;
    }
    
    void helper(TreeNode* root , int low , int high , TreeNode* parent){
        
        if(!root) return;
        //cout<<parent->val<<" -> "<<root->val<<endl;
        if(root->val < low){
            parent->left = root->right;
            helper(parent->left , low , high , parent);
        }
        else if(root->val > high){
            parent->right = root->left;
            helper(parent->right , low , high , parent);
        }
        else{
            helper(root->left , low , high , root);
            helper(root->right , low , high , root);
        }
        
    }
};