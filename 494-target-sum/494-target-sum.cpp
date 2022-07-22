class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if( abs(target) > sum || (sum+target)%2==1 ) return 0;
        
        sum = (sum + target) / 2;
        
        int dp[n+1][sum+1];
        for(int i = 0 ; i < sum+1 ; i++) dp[0][i] = 0;
        dp[0][0] = 1;
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 0 ; j < sum+1 ; j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};