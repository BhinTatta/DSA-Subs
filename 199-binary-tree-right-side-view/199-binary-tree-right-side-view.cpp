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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int , int > mp;
        
        helper(root , mp , 0 , ans);
        
//         for(auto x : mp){
//             ans.push_back(x.second);
//         }
        
        return ans;
    }
    
    void helper(TreeNode* root , map<int,int> &mp , int level , vector<int> &ans ){
        if(!root) return;
        
        // if(!mp[level]){
        //     mp[level] = root->val;
        // }
        int size = ans.size();
        
        if(level == size){
            ans.push_back(root->val);
        }
        
        helper(root->right , mp , level+1 , ans);
        helper(root->left , mp , level+1 , ans);
        
    }
};