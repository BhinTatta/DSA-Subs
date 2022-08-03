class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,-1));
        return trade(prices , 0 , true , dp);
    }
    
    int trade(vector<int>&prices , int i , bool buy , vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int notrade = trade(prices , i+1 , buy , dp);
        
        int dotrade;
        if(buy){
            dotrade = -prices[i] + trade(prices , i+1 , !buy , dp);
        }
        else if(!buy){
            dotrade = prices[i] + trade(prices , i+2 , !buy , dp);
        }
        
        return dp[i][buy] = max(dotrade,notrade);
    }
};