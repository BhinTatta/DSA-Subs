class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n==0 || m==0) return max(n,m);
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        for(int i = 0 ; i <= n ; i ++) dp[i][0] = i;
        for(int i = 0 ; i <= m ; i++) dp[0][i] = i;
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int del = 1 + dp[i-1][j];
                    int ins = 1 + dp[i][j-1];
                    int rep = 1 + dp[i-1][j-1];        
                    dp[i][j] = min(del , min(ins , rep));
                }
            }
        }
        return dp[n][m];
    }
    
};