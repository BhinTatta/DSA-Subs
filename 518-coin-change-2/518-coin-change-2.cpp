class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp( n+1 , vector< int>( amount +1 , 0 ) );
        dp[0][0] = 1;
        
        for( int i = 1 ; i < n+1 ; i++){
            for(int j = 0 ; j < amount+1 ; j++){
                int take = 0, dont = 0;
                if(coins[i-1]<=j){
                    take = dp[i][j-coins[i-1]];
                    dont = dp[i-1][j];
                }
                else{
                    dont = dp[i-1][j];
                }
                dp[i][j] = take + dont;
            }
        }
        return dp[n][amount];
    }
};