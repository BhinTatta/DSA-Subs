class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        helper(nums,ans,0);
        return ans;
    }
    
    void helper(vector<int> &nums , vector<vector<int>> &ans , int idx){
        if(idx>=n){
            ans.push_back(nums);
            return;
        }
        
        for(int i = idx ; i < n ; i++){
            swap(nums[idx] , nums[i]);
            helper(nums , ans , idx+1);
            swap(nums[i] , nums[idx]);
        }
        return;
    }
};