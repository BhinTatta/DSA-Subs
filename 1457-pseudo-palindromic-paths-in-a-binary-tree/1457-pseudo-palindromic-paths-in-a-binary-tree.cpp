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
    long long ans = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10,0);
        helper(root , mp);
        return ans;
    }    
    
    void helper(TreeNode* root , vector<int> mp){
        if(!root){
            return;
        }
        
        int pos = root->val;
        mp[pos]+=1;    
        
        if(!root->left && !root->right){
            if(ispalind(mp)) ans++;
            return;
        }
        
        helper(root->left , mp);
        helper(root->right , mp);     
    }
    
    bool ispalind(vector<int>&mp){
        int odd = 0;
        for(int x : mp){
            odd += x%2;
        }
        return odd<2;
    }
};