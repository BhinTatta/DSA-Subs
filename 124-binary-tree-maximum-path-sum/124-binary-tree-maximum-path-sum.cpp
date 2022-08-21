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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxsum = INT_MIN;
        helper(root, maxsum);
        return maxsum;
    }
    
    int helper(TreeNode* root , int &maxsum){
        
        if(!root->left && !root->right){
            maxsum = max(maxsum , root->val);
            return root->val;
        }
        
        int l = -1001 , r = -1001;
        
        if(root->left) l = helper(root->left , maxsum );
        if(root->right) r  = helper(root->right , maxsum );
        
        int maxi = root->val;
        
        maxi += max(l,r);
        
        int maxi3 = root->val;
        
        maxi = max(maxi , maxi3);
        int maxi2 = root->val + l + r ; 
               
        maxsum = max(maxsum , max(maxi , maxi2));
        return maxi;
    }
};