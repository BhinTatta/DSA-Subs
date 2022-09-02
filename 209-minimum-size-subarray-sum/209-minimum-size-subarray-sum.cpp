class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int>dp(n+1,0);
        
        for(int i = 1 ; i <= n ; i++){
            dp[i] = sum + nums[i-1] ;
            sum = dp[i];
        }
        
        int ans = INT_MAX, i = n;
        while(i>0){
            if(dp[i]<k) break;
            int j = upper_bound(dp.begin() , dp.end() , dp[i]-k) - dp.begin();
            ans  = min(ans , i-j+1);
            i--;
        }
        return ans==INT_MAX?0:ans;
    }
};