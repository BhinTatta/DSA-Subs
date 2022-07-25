class Solution {
public:
    int n , k;
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp( n+1 , vector<int>(amount+1 , INT_MAX-1));
        dp[0][0]=1;
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 0 ; j < amount+1 ; j++){
                int take = INT_MAX, dont = INT_MAX;
                if(coins[i-1]<=j){
                    take = 1 + dp[i][j-coins[i-1]];
                    dont = dp[i-1][j];
                }
                else{
                    dont = dp[i-1][j];
                }
                
                dp[i][j] = min( take , dont);
            }
        }
        return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount]-1;
    }
    
    int helper( vector<int> &coins , int amount , int i , int cc , vector<vector<int>> &dp){
        if( i == n){
            if(amount == 0) return cc;
            return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take = INT_MAX, dont = INT_MAX;
        
        if(coins[i] <= amount ){
            take = helper(coins , amount - coins[i] , i , cc+1 , dp);
            dont = helper(coins , amount , i+1 , cc , dp);
        }
        else{
            dont = helper(coins , amount , i+1 , cc , dp);
        }
        
        return dp[i][amount] = min(take,dont);
    }
};