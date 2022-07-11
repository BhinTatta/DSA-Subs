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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int > mp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        int pstart = 0 , pend = preorder.size()-1 , istart = 0 , iend = pend;
        
        TreeNode* root = build(preorder , pstart , pend , inorder , istart , iend , mp);
        
        return root;
    }
    
    TreeNode* build(vector<int>& preorder, int pstart , int pend , vector<int>& inorder , int istart , int iend , map<int , int > &mp){
        
        if(pstart > pend || istart > iend) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pstart]);
        
        int inRoot = mp[root->val];
        int numsLeft = inRoot - istart;
        
        root->left = build(preorder , pstart+1 , pstart+numsLeft , inorder , istart , inRoot-1 , mp);
        root->right = build(preorder , pstart + numsLeft + 1 , pend , inorder , inRoot+1 , iend , mp);
        
        return root;
    }
};