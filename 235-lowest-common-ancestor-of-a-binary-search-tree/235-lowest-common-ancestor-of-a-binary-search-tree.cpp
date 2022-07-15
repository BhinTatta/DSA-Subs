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
        
        int pval = p->val;
        int qval = q->val;
        int temp = pval;
        pval = min(pval , qval);
        qval = max(temp , qval);
        
        return helper(root , pval , qval);
    }
    
    TreeNode* helper(TreeNode* root , int pval , int qval){
        if(!root) return nullptr;
        
        int currval = root->val;
        
        if(pval <= currval && qval >= currval) return root;
        
        TreeNode* ans;
        
        if(pval < currval &&  qval < currval) ans = helper(root->left , pval , qval);
        if(pval > currval && qval > currval) ans = helper(root->right , pval , qval);
        
        return ans;
    }
};