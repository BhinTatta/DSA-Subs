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
    void recoverTree(TreeNode* root) {
        TreeNode* pos_inf = new TreeNode(INT_MAX);
        TreeNode* neg_inf = new TreeNode(INT_MIN);
        bool ans = false;
        while(!ans){
            ans = helper(root , pos_inf , neg_inf);
        }
    }
    
    bool helper(TreeNode* root , TreeNode* upper , TreeNode* lower){
        if(!root) return true;
        
        int up = upper->val;
        int down = lower->val;
        int curr = root->val;
        
        if(curr < down){
            //cout<<"swap"<<" "<<curr <<" "<<down<<endl;
            root->val = down;
            lower->val = curr;
            return false;
        }
        else if(curr > up){
            //cout<<"swap"<<" "<<curr <<" "<<up<<endl;
            root->val = up;
            upper->val = curr;
            return false;
        }
        
        return helper(root->left , root , lower) && helper(root->right , upper , root);
        
    }
};