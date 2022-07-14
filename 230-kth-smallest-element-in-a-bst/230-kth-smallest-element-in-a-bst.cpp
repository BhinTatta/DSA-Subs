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
    int ans = 0 , i = 0;
    
    int kthSmallest(TreeNode* root, int k) {
        helper(root , k);
        return ans;
    }
    
    void helper(TreeNode* root , int k ){
        if(!root) return;
        if(root->left) helper(root->left , k);
        i++;
        if(i==k) ans = root->val;
        if(root->right) helper(root->right , k);
    }
};