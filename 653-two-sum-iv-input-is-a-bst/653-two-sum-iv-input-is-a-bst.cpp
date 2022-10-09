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
    unordered_map<int,int> mp;
    bool flag = false;
    
    bool findTarget(TreeNode* root, int k) {
        return helper(root , k);
    }
    
    bool helper(TreeNode* root , int k){
        if(!root || flag ) return false;
        
        int req = k - root->val;
        if(mp.find(req)!=mp.end()){
            flag = true;
            return true;
        }
        mp[root->val]++;
        bool a = helper(root->left , k);
        bool b = helper(root->right , k);
        
        return a||b;
    }
};