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
    vector<long long> prev;
    long long total = 0;
    
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;
    
        
        helper(root , target , prev , total);
        return total;
    }
    
    void helper(TreeNode* root , int target , vector<long long> prev , long long &total){
        if(!root) return;
        
        long long curr = root->val;
        if(curr==target) total++;
        for(int i = 0 ; i < prev.size() ; i++ ){
            if(prev[i]+curr == target) total++;
            prev[i]+=curr;
            //cout<<prev[i]+curr<<" ";
        }
        //cout<<endl;
        prev.push_back(curr);
        
        helper(root->left , target , prev , total);
        helper(root->right , target , prev , total);
        
        prev.pop_back();
        return;
    }
};