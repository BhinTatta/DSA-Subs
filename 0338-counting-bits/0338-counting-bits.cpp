class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);

        int pow = 1;
        for(int i = 1 ; i <= n ; i++){
            if(pow*2 == i) pow = i;
            dp[i] = 1 + dp[i - pow];
        }
        return dp;
    }
};