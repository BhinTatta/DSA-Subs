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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return ans;
        vector<int> temp;
        helper(root,temp,sum);
        return ans;
    }
    
    void helper(TreeNode* root , vector<int> temp , int sum){
        if(!root->left && !root->right){
            if(root->val == sum){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
        sum -= root->val;
        
        temp.push_back(root->val);
        if(root->left) helper(root->left , temp , sum);
        if(root->right) helper(root->right , temp , sum);
        
    }
};














