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
    int ans = INT_MIN;
    
    int maxAncestorDiff(TreeNode* root) {
        helper(root, root->val, root->val);
        return ans;
    }
    
    void helper(TreeNode* root , int mini , int maxi){
        if(!root) return;
        int a = abs(mini - root->val) , b = abs(maxi - root->val);
        ans = max(ans , max(a,b));
        mini = min(root->val , mini);
        maxi = max(root->val , maxi);
        helper(root->left , mini , maxi);
        helper(root->right , mini , maxi);
    }
};