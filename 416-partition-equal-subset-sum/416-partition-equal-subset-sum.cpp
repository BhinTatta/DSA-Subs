class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        if(sum%2==1) return false;
        sum = sum/2;
        
        bool dp[n+1][sum+1];
        
        for(int i = 0 ; i <= sum ; i++){
            dp[0][i]= false;
        }
        dp[0][0] = true;
        // for(int i = 0 ; i <= n ; i++){
        //     dp[i][0]= true;
        // }
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= sum ; j++){
                
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                }
                else if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};