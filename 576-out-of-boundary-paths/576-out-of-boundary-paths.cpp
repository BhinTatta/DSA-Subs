class Solution {
public:
    int mod = 1000000007;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(52 , vector<vector<int>>(52 , vector<int>(52,-1)));
        return dfs( m , n , startRow , startColumn , maxMove , dp);
    }
    
    int dfs(int m , int n , int r , int c , int move , vector<vector<vector<int>>> &dp){
        if(move < 0) return 0;
        //if ( (r==0 || r==m-1) && (c==0 || c== n-1) )  return 2;
        if( r<0 || r >= m || c<0 || c >=n ) return 1; 
        
        if(dp[r][c][move]!=-1) return dp[r][c][move];
        int total = 0;
        total = (total + dfs(m , n , r-1 , c , move-1 , dp))%mod ;
        total = (total + dfs(m , n , r+1 , c , move-1 , dp))%mod;
        total = (total +dfs(m , n , r , c-1 , move-1 ,dp))%mod ;
        total = (total +dfs(m , n , r , c+1 , move-1 , dp))%mod ;
        
        return dp[r][c][move] = (total)%mod;
    }
};