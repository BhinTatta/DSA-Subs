class Solution {
public:
    int mod = 1e9 + 7;
    int dp[35][1005];
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp , -1 ,sizeof(dp));
        long long int ans = 0;
        for(int i = 1 ; i <= k ; i++){
            ans += helper(n-1 , target-i , k) % mod;
        }
        return ans%mod;
    }
    
    int helper(int n , int target , int k ){
        if(n == 0 || target<=0){
            if(target==0 && n==0) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        long long int ans = 0;
        for(int i = 1 ; i <= k ; i++ ){
            ans += helper(n-1 , target-i , k) % mod;
        }
        
        return dp[n][target] = ans%mod;
    }
};