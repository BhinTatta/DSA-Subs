class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int maxi = 0;
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[j] < nums[i]) maxi = max(maxi , dp[j]);
            }
            dp[i] = 1 + maxi;
            ans = max(ans , dp[i]);
        }
        
        return ans;
    }
};