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
    int countNodes(TreeNode* root) {
        int ans = helper(root);
        return ans;
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        TreeNode* temp1 = root , *temp2 = root;
        int l = 0 , r = 0;
        while(temp1){
            l++;
            temp1 = temp1->left;
        }
        while(temp2){
            r++;
            temp2 = temp2->right;
        }
        if(l==r){
            return pow(2,l)-1;
        }
        return 1 + helper(root->left) + helper(root->right);
    }
};