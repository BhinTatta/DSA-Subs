class Solution {
public:
    int longestPalindromeSubseq(string one) {
        string s1 = one;
        reverse(one.begin() , one.end());
        string s2 = one;
        
        int n = s1.length();
        int m = n;
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        
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
        
        return dp[n][m];
    }
};