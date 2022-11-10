class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1002];
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(1, n , delay , forget);
        return ans;
    }
    
    int helper(int curr , int n , int d , int forget){
        long long int ans = 1;
        if(dp[curr]!=-1) return dp[curr];
        if(curr+forget <= n) ans--;
        
        for(int i = curr+d ; i < min(n+1 , (curr+forget)) ; i++){
            ans = (ans + helper(i,  n , d , forget) )%mod;
        }
        return dp[curr] = ans%mod;
    }
};