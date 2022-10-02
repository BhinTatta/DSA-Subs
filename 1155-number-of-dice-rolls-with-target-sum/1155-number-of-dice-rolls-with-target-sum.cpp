class Solution {
public:
    //copying it, going to santosh dhaba, will do it tonight
    typedef long long ll;
    ll mod = 1e9 + 7;
    ll dp[35][1005];

    ll recurse(int turn, int target, int n, int k) {
        if(target < 0) return 0;
        if(turn == n) {
            return (target == 0);
        }
        if(dp[turn][target] != -1) return dp[turn][target];
        ll ways = 0;
        for(int i = 1; i <= min(k, target); i++) {
            ways = (ways + recurse(turn+1, target - i, n, k)) % mod;
        } 
        return dp[turn][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof dp);
        return recurse(0, target, n, k);
    }
};