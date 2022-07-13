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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        helper(root,val);
        return root;
    }
    
    void helper(TreeNode* root , int val){
        int curr = root->val;
        
        if(val < curr){
            if(root->left==nullptr){
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return;
            }
            else{
                helper(root->left , val);
            }
        }
        if(val > curr){
            if(root->right==nullptr){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }
            else{
                helper(root->right , val);
            }
        }
    }
};