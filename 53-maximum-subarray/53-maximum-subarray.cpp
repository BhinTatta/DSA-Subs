class Solution {
public:
    int n;
    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(2 , vector<int>(n+1,-1));
        return helper(nums, 0 , false , dp);
    }
    
    int helper(vector<int>&nums, int i , bool state , vector<vector<int>> &dp){
        if(i==n){
            return state==true ? 0 : -1e5;
        }
        if(dp[state][i]!=-1) return dp[state][i];
        int take , dont;
        
        if(state){
            return dp[state][i] = max(0 , nums[i] + helper(nums,i+1,true,dp));
        }
        
        
        return dp[state][i] = max( helper(nums,i+1,false,dp) , nums[i]+helper(nums,i+1,true,dp));
    }
};