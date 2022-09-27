class Solution {
public:
    int dp[5005][2];
    int maxProfit(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n = nums.size();
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= 1 ; j++){
                if(j==1){
                    int sell = dp[i+2][0] + nums[i];
                    int dont = dp[i+1][1];
                    dp[i][j] = max(sell , dont); 
                }
                else{
                    int buy = dp[i+1][1] - nums[i];
                    int dont = dp[i+1][0];
                    dp[i][j] = max(buy,dont);
                }
            }
        }
        
        
        return dp[0][0];
    }

};