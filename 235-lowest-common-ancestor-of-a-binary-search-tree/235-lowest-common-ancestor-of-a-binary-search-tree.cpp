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
        TreeNode* ans = nullptr;
        TreeNode* temp;
        if(p->val > q->val){
            temp = p;
            p = q;
            q = temp;
        }
        helper(root,p->val,q->val,ans);
        return ans;
    }
    
    void helper(TreeNode* root, int p, int q, TreeNode* &ans){
        if(!root || ans!=nullptr) return;
        
        bool left , right;
        
        if(root->val>=p && root->val<=q){
            ans = root;
            return;
        } 
        else{
            helper(root->left , p ,q ,ans);
            helper(root->right , p ,q,ans);
        }
    }
};