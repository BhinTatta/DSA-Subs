class Solution {
public:
    long long int dp[60];
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        dp[3]=2;
        return helper(n);
    }
    
    int helper(int n){
        if(n<=2) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MIN;
        for(int i = 1 ; i <n ; i++){
            int temp = i * max(n-i , helper(n-i));
            ans = max(ans,temp);
        }
        return dp[n] = ans;
    }
};