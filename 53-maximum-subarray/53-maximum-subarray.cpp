class Solution {
public:
    int n;
    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(2 , vector<int>(n+1,-1));
        dp[0][0] = nums[0];
        dp[1][0] = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            dp[1][i] = max(nums[i] , nums[i]+dp[1][i-1]);
            
            dp[0][i] = max(dp[0][i-1] , dp[1][i]  );
        }
        return dp[0][n-1];
    }

};