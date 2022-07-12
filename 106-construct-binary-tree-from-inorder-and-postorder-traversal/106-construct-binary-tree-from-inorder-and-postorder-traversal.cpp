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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int istart = 0 , iend = inorder.size()-1 , pstart = 0 , pend = iend;
        unordered_map<int , int> mp;
        
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]]=i;
        }
        
        TreeNode* root = builder(inorder,istart,iend,postorder,pstart,pend,mp);
        
        return root;
    }
    
    TreeNode* builder(vector<int> inorder , int istart , int iend , vector<int>postorder , int pstart , int pend , unordered_map<int,int> &mp){
        
        if(istart>iend || pstart > pend) return nullptr;
        
        TreeNode* root = new TreeNode( postorder[pend] );
        int iroot = mp[root->val];
        int ileft = iroot-istart;
        
        root->left = builder(inorder , istart , iroot-1 ,postorder , pstart , pstart+ileft-1 , mp);
        root->right = builder(inorder , iroot+1 , iend , postorder , pstart+ileft , pend-1 , mp);
        return root;
        
    }
};