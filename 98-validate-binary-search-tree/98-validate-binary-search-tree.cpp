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
    bool isValidBST(TreeNode* root) {
        return bst(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
    
    bool bst(TreeNode* root , long long mini , long long maxi){
        if(!root) return true;
        long long curr = root->val;
        if(curr<= mini || curr>= maxi) return false;
        
        bool l = bst(root->left , mini , root->val);
        bool r = bst(root->right , root->val , maxi);
        
        return l&&r;
    }
};