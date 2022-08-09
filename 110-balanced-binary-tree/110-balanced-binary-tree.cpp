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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag = true;
        helper(root ,  flag);
        return flag;       
    }
    
    int helper(TreeNode* root,  bool &flag){
        if(!flag) return 0;
        if(!root->left && !root->right) return 1;
        int l = 0 , r = 0;
        
        if(root->left){
            l = helper(root->left , flag);
        }
        if(root->right){
            r = helper(root->right , flag);
        }
        if(abs(r-l) > 1) flag=false;
        return 1 + max(l , r);
    }
};