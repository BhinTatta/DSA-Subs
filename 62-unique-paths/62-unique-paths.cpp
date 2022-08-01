class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans = 0;
        int r = 0 , c = 0;
        if(n==1 && m==1 )return 1;
        vector<vector<int>> dp(m , vector<int> (n,-1));
        int x = helper( r , c , m , n , ans , dp);
        return dp[0][0];
    }
    
    int helper(int r , int c , int m , int n , int &ans , vector<vector<int>> &dp){
        if(r >= m || c >= n) return 0;
        if(r == m-1 && c == n-1){
            ans++;
            return 1;
        }
        
        if(dp[r][c] !=- 1) return dp[r][c];
        
        int down = helper( r+1 , c , m , n ,ans ,dp);
        int right = helper(r , c+1 , m , n , ans ,dp);
        
        return dp[r][c] = down+right;
    }
};