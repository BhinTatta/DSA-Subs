class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        vector<int> dp(1e6+5 , 0);
        
        for(auto i : nums){
            dp[i[0]]++;
            dp[i[1]+1]--;
        }
        
        int ans = dp[0];
        for(int i = 1 ; i < dp.size() ; i++){
            dp[i] += dp[i-1];
            ans = max(dp[i] , ans);
        }
        
        return ans;
    }
};