class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
        return helper(s1,s2,n-1,m-1,dp);
    }
    
    int helper(string &s1, string &s2 , int i , int j ,  vector<vector<int>> &dp){
        if(i<0 || j<0){
            if(i<0 && j<0) return 0;
            else return max(i+1,j+1);
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans;
        if(s1[i]==s2[j]) ans = helper(s1,s2,i-1,j-1,dp);
        else{
            int del = 1 + helper(s1,s2,i-1,j,dp);
            int ins = 1 + helper(s1,s2,i,j-1,dp);
            int rep = 1 + helper(s1,s2,i-1,j-1,dp);
            
            ans = min(del , min(ins , rep));
        }
        return dp[i][j] = ans;
    }
};