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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int , int > mp;
        return helper(root , k , mp);
    }
    
    bool helper(TreeNode* root , int k , unordered_map<int , int> &mp){
        if(!root) return false;
        
        int curr = root->val;
        if(mp[k-curr])  return true;
        mp[curr]++;
        
        bool l = helper(root->left , k , mp);
        bool r = helper(root->right , k , mp);
        
        return l||r;
    }
};