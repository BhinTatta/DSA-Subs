class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(target+1,-1);
        ans += solver(nums,target,n,0,dp);

        return ans;
    }
    
    int solver(vector<int>& nums, int target, int n, int i, vector<int> &dp){
        if(target==0) return 1;
        if(i >= n) return 0;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int k = 0 ; k < n ; k++){
            if(nums[k]<=target){
                ans += solver(nums, target-nums[k] , n, k , dp);
            }
        }
        return dp[target] = ans;
    }
};