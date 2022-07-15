class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n,-1);
        
        int one = rober(nums , 0 , dp);
        int two = rober(nums , 1 , dp);
        
        return max(one,two);
    }
    
    int rober(vector<int>& nums , int i , vector<int> &dp){
        if(i>=n) return 0;
        if(i == n-1) return nums[n-1];
        
        if(dp[i]!= -1) return dp[i];
        int rob = nums[i] + rober(nums , i+2 , dp);
        int leave = rober(nums , i+1 , dp);
        
        return dp[i] = max(rob , leave);
    }
};