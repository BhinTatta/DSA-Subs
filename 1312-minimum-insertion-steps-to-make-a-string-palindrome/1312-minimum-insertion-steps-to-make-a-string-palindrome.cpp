class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin() , s.end());
        string s2 = s;
        int n = s1.length();
        int m = n;
        int dp[n+1][m+1];
        memset(dp , 0, sizeof(dp));
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max( dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        
        return n - dp[n][m];
    }
};