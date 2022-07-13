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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        helper(ans , q);
        return ans;
    }
    
    void helper(vector<vector<int>> &ans , queue<TreeNode*> &q ){
        if(q.empty()) return;
        queue<TreeNode*> newq;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* tempnode = q.front();
            if(tempnode->left){
                newq.push(tempnode->left);
            }
            if(tempnode->right){
                newq.push(tempnode->right);
            }
            temp.push_back(tempnode->val);
            q.pop();
        }
        ans.push_back(temp);
        helper(ans , newq);
    }
    
};