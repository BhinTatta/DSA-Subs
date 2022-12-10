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
private:
    long long int sum = 0 , ans = 0;
    int mod = 1e9+7;
public:
    int maxProduct(TreeNode* root) {
        tsum(root);        
        helper(root);
        return ans%mod;
    }
    
    long long int helper(TreeNode* root){
        if(!root) return 0;
        long long int l = helper(root->left) , r = helper(root->right);
        long long int curr = root->val + l + r;
        ans = max(ans , curr*(sum-curr));
        //cout<<curr<<" * "<<sum-curr<<endl;
        return curr;
    }
    
    void tsum(TreeNode* root){
        if(!root) return;
        sum += root->val;
        tsum(root->left);
        tsum(root->right);
    }
};