class Solution {
public:
    int dp[2505][2505];
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp , -1, sizeof(dp));
        int ans = 0,  n = nums.size();
        for(int i = 0 ; i < n-1 ; i++){
            ans = max( ans , helper(nums , i+1 , i) );
        }
        return 1 + ans;
    }
    
    int helper(vector<int> &nums , int i , int prev){
        if(i >= nums.size()) return 0;
        
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int a = helper(nums , i+1 , prev);
        int b = 0;
        if(nums[i]>nums[prev]){
            b = 1+helper(nums,i+1,i);
        }
        return dp[i][prev] = max(a,b);
    }
};