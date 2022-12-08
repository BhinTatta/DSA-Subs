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
private:
    vector<int> v1,v2;
    
    void helper(TreeNode* root , vector<int> &vec){
        if(!root) return;
        if(!root->left && !root->right){
            vec.push_back(root->val);
            return;
        }
        helper(root->left , vec);
        helper(root->right , vec);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1 , v1);
        helper(root2 , v2);
        return v1 == v2;
    }
};