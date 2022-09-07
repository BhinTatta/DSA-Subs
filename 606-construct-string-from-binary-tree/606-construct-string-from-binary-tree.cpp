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
    
    string tree2str(TreeNode* root) {
        string ans = helper(root);
        return ans;
    }
    
    string helper(TreeNode* root){
        if(!root) return "";
        if(!root->left && !root->right){
            string temp =  to_string(root->val);
            return temp;
        }
        
        string temp;
        temp += to_string(root->val);
        
        string l , r;
        
        l = helper(root->left);
        r = helper(root->right);
        
        if(l.length()==0 && r.length()!=0){
            temp += "()";
            temp += "(" + r + ")";
        }
        else{
            temp += "(" + l + ")";
            if(r.length()!=0) temp += "(" + r + ")";
        }
        
        return temp;
        
    }
};










