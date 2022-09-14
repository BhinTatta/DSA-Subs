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
    int ans = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return ans;
    }    
    
    void helper(TreeNode* root , int count = 0){
        if(!root){
            return;
        }
        count = count^(1<<root->val); 
        
        if(!root->left && !root->right){
            if( (count&count-1) == 0) ans++;
        }  
        helper(root->left , count);
        helper(root->right , count);  
        
        count=count^(1<<root->val);
    }
    
};