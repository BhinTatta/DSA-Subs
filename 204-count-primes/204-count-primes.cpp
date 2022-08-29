class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        int ans = 0;
        for(long long int i = 0 ; i < n ; i++){
            if(dp[i]==0){
                ans++;
                long long int x = 2;
                while(x*i < n){
                    dp[x*i]=1;
                    x++;
                }
            }
        }
        
        // int ans = 0;
        // for(int x : dp) if(x==0) ans++;
        return ans;
        
    }
};