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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while( temp ||!st.empty()){
            if(temp){
                st.push(temp);
                temp = temp->left;
                continue;
            }
            if(!temp && !st.empty()){
                TreeNode* curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                temp = curr->right;
            }
        }
        
        return ans;
    }
    
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         vector<int> ans;
//         helper(root , ans);
//         return ans;
//     }
    
//     void helper(TreeNode* root, vector<int> &ans){
//         if(!root) return;
//         helper(root->left , ans);
//         ans.push_back(root->val);
//         helper(root->right , ans);
//     }
};