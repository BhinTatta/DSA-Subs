class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int>dp(n,1) , dp2(n,1);
        for(int i = 1 ; i < n ; i++) if(nums[i]>nums[i-1]) dp[i] = dp[i-1]+1;
        for(int i = n-2 ; i >= 0 ; i--) if(nums[i]>nums[i+1]) dp2[i] = dp2[i+1]+1;       
        int ans = 0;
        for(int i = 0 ; i < n ; i++) ans += max(dp[i],dp2[i]);
        return ans;
    }
};