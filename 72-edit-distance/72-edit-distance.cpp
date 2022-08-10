class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0 ; i <= n ; i++)dp[i][0]=i;
        for(int i = 0 ; i <= m ; i++)dp[0][i]=i;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <=m ; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int insert = dp[i-1][j];
                    int delt = dp[i][j-1];
                    int rep = dp[i-1][j-1];
                    dp[i][j] = 1 + min(insert , min(delt,rep));
                }
            }
        }
        
        return dp[n][m];
    }
};