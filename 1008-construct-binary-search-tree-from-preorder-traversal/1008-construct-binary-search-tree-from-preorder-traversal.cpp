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
    int n , i;
    TreeNode* bstFromPreorder(vector<int>& nums) {
        n = nums.size();
        i = 0;
        return helper(nums, i , INT_MAX);
    }
    
    TreeNode* helper(vector<int> &nums , int &i , int upper){
        if(i >= n) return nullptr;
        if(nums[i] > upper) return nullptr;
        
        TreeNode* root = new TreeNode(nums[i]);
        i++;
        root->left = helper(nums , i , root->val );
        root->right = helper(nums , i , upper);
        
        return root;
    }
};