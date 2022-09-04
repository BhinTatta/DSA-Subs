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
    void helper( queue<pair<TreeNode*,int>> &q , map<int , vector<int>> &mp){
        if(q.empty()) return;
        int qsize = q.size();
        map<int , vector<int>> mp2;
        //vector<int> temp;
        for(int i = 0 ; i < qsize ; i++){
            //Node* curr = q.front();
            TreeNode* currnode = q.front().first;
            int level = q.front().second;
            q.pop();
            mp2[level].push_back(currnode->val); 
            
            if(currnode->left) {
                q.push(make_pair(currnode->left , level-1));
            }
            if(currnode->right) {
                q.push(make_pair(currnode->right , level+1));
            }
        }
        for(auto level : mp2){
            int currlevel = level.first;
            sort(level.second.begin() , level.second.end());
            
            for(int i = 0 ; i < level.second.size() ; i++){
                mp[currlevel].push_back(level.second[i]);
            }
        }
        helper(q , mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans2;
        if(!root) return ans2;
        q.push(make_pair(root , 0));
        helper(q , mp);
        
        for(auto level : mp){
            ans2.push_back(level.second);
        }
        
        return ans2;
    }
};