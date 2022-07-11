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
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;
    
        vector<long long> prev;
        long long total = 0;
        helper(root , target , prev , total);
        return total;
    }
    
    void helper(TreeNode* root , int target , vector<long long> prev , long long &total){
        if(!root) return;
        
        long long curr = root->val;
        vector<long long> newprev;
        if(curr==target) total++;
        for(int i = 0 ; i < prev.size() ; i++ ){
            if(prev[i]+curr == target) total++;
            newprev.push_back(prev[i]+curr);
            //cout<<prev[i]+curr<<" ";
        }
        //cout<<endl;
        newprev.push_back(curr);
        
        helper(root->left , target , newprev , total);
        helper(root->right , target , newprev , total);
        
        return;
    }
};