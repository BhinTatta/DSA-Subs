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
    vector<int> nums;
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        helper(root);
        //nums.insert(nums.begin() , 0);
        int n = nums.size();
        vector<vector<int>> ans;
        // for(int i : nums) cout<<i<<" ";
        // cout<<endl;
        for(int x : queries){
            vector<int> temp;
            
            int l = lower_bound(nums.begin() , nums.end() , x) - nums.begin();
            
            if(l!=n && nums[l]==x){
                ans.push_back({x,x});
                continue;
            }
            int a , b;
            l==0 ? a = -1 : a = nums[l-1];
            l==n ? b = -1 : b = nums[l];
            ans.push_back({a,b});
            
        }
        
        return ans;
    }
    
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        nums.push_back(root->val);
        helper(root->right);
    }
};