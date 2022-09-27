class Solution {
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(prices , 0 , false);
    }
    
    int helper(vector<int>&nums , int i , bool state){
        if(i >= nums.size()) return 0;
        
        if(dp[i][state]!=-1) return dp[i][state];
        
        int ans = 0;
        
        if(state){
            int sell = helper(nums,i+2,!state) + nums[i];
            int dont = helper(nums,i+1,state);
            ans = max(sell , dont);
        }
        else{
            int buy = helper(nums,i+1,!state) - nums[i];
            int dont = helper(nums,i+1,state);
            ans = max(buy,dont);
        }
        
        return dp[i][state] = ans;
    }
};