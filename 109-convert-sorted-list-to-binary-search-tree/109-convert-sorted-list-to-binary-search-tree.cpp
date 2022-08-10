/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> nums;
        while(head!=nullptr){
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }
    
    TreeNode* helper(vector<int>&nums , int l , int r){
        if(l>r) return nullptr;
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums , l , mid-1);
        root->right = helper(nums , mid+1 , r);
        return root;       
    }
};