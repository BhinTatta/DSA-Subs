class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;        
        for(int i = 2 ; i < n ; i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) dp[i] = 1+dp[i-1];
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};