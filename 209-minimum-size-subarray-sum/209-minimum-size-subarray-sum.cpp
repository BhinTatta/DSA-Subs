class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        // int dp[n];
        // memset(dp,0,sizeof(dp));
        // for(int i = 0 ; i < n ; i++) dp[i]=sum+nums[i]; sum = dp[i];
        
        int l = 0 , r = 0;
        int ans = INT_MAX;
        sum = 0;
        while(r<n){
            sum+=nums[r];        
            if(sum>=k){     
                ans = min(ans, r-l+1);
                while(l<r && sum>=k){
                    sum -= nums[l];
                    l++;
                    if(sum>=k) ans = min(ans, r-l+1);
                }
            }
            r++;
        }
        return ans==INT_MAX?0:ans;
    }
};