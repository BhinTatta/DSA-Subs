class Solution {
private:
    int n;
    int dp[101];
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1) return nums[0];
        memset(dp,0,sizeof(dp));
        dp[1] = nums[0];
        for(int i = 2 ; i <= n ; i++){
            int rob = nums[i-1] + dp[i-2];
            int dont = dp[i-1];
            dp[i] = max(rob , dont);
        }
        return dp[n];
    }
    
};