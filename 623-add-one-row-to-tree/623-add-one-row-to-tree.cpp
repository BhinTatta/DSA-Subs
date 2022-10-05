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
    void getrow(TreeNode* root , int d){
        queue<TreeNode*> q;
        q.push(root);
        
        while(d-->1){
            int n = q.size();
            queue<TreeNode*> newq;
            while(n-->0){
                auto curr = q.front();
                q.pop();
                if(curr->left) newq.push(curr->left);
                if(curr->right) newq.push(curr->right);
            }
            q = newq;
        }
        
        while(!q.empty()){
            row.push_back(q.front());
            q.pop();
        }
    }
    
    void adder(vector<TreeNode*> row , int val){
        for(auto node : row){
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            TreeNode* temp1 = new TreeNode(val , l , nullptr);
            TreeNode* temp2 = new TreeNode(val , nullptr , r);
            node->left = temp1;
            node->right = temp2;
        }
    }
    
    
public:
    vector<TreeNode*> row;
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* temp = new TreeNode(val , root, nullptr);
            return temp;
        }
        
        getrow(root,depth-1);  
        adder(row , val);
        return root;
    }
};




















