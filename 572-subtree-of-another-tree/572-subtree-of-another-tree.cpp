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
    vector<TreeNode*> vec;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        finder(root , subRoot);        
        for(int i = 0 ; i < vec.size() ; i++){
            if(dfs( subRoot , vec[i] ) ) return true;
        }
        return false;
    }
    
    bool dfs(TreeNode* subRoot , TreeNode* intree){
        if((subRoot && !intree) || (!subRoot && intree)) return false;
        if(!subRoot && !intree) return true;
        //cout<<subRoot->val <<" "<< intree->val<<endl;
        if(subRoot->val != intree->val) return false;
        
        bool l = dfs(subRoot->left , intree->left);
        bool r = dfs(subRoot->right , intree->right);
        
        return l&&r;
    }
    
    void finder(TreeNode* root , TreeNode* subRoot){
        if(!root) return;        
        if(root->val==subRoot->val){
            vec.push_back(root);
        };        
        finder(root->left , subRoot);      
        finder(root->right , subRoot);       
    }
};