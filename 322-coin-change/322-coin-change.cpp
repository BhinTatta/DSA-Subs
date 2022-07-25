class Solution {
public:
    int n , k;
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        int dp[amount+1];
        for(int i = 0 ; i < amount+1 ; i++) dp[i] = INT_MAX-1;
        dp[0]=0;
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 0 ; j < amount+1 ; j++){
                int take = INT_MAX, dont = INT_MAX;
                if(coins[i-1]<=j){
                    take = 1 + dp[j-coins[i-1]];
                    dont = dp[j];
                }
                else{
                    dont = dp[j];
                }             
                dp[j] = min( take , dont);
            }
        }
        
        return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
    }

};