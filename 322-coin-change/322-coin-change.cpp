class Solution {
public:
    int n;
    
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp(amount+1 , vector<int>(n+1 ,-1));
        int ans = helper(coins , amount , dp , 0 , 0);
        ans > amount ? ans = -1 : ans = ans;
        return ans;
    }
    
    int helper(vector<int>& coins , int amount , vector<vector<int>> &dp , int i , int cc){
        if(amount < 0 || i >=n) return INT_MAX-1;
        if(amount == 0) return 0;
        
        if(dp[amount][i]!=-1) return dp[amount][i];
        
        int mini = -1;
        if(coins[i] > amount){
            int donttake = helper(coins , amount , dp , i+1 , cc);
            mini = donttake;
        }
        else{
            int take = 1 + helper(coins , amount-coins[i] , dp , i , cc);
            int donttake = helper(coins , amount , dp , i+1 , cc);
            dp[amount][i] = mini = min(take , donttake);
        }
        
        return dp[amount][i] = mini;
    }
};