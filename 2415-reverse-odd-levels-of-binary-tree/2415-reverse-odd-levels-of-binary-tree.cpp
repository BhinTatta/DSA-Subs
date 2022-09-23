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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bfs(q,false);
        return root;
    }
    
    void bfs( queue<TreeNode*> q , bool odd){
        if(q.empty()) return;
        vector<TreeNode*> vec;
         queue<TreeNode*> newq;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(odd)vec.push_back(curr);
            if(curr->left) newq.push(curr->left);
            if(curr->right) newq.push(curr->right);
        }
        if(odd) rev(vec);
        bfs(newq , !odd);
    }
    
    void rev(vector<TreeNode*> &vec){
        int i = 0 , j = vec.size()-1;
        while(i<j){
            int temp = vec[i]->val;
            vec[i]->val = vec[j]->val;
            vec[j]->val = temp;
            i++;
            j--;
        }
    }
};
















