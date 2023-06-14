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
    vector<int> dp;
public:
    void helper(TreeNode* root){
        if(!root) return;
        dp.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        sort(dp.begin() , dp.end());
        int ans = INT_MAX;
        
        for(int i = 0 ; i < dp.size()-1 ; i++){
            ans = min(ans , abs(dp[i]-dp[i+1]) );
        }
        
        return ans;
    }
};