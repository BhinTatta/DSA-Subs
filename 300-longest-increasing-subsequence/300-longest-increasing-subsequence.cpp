class Solution {
public:
    int dp[2505][2505];
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        int ans = helper(nums , 0 , -1);
        return ans;
    }
    
    int helper(vector<int> &nums , int i , int prev){
        if(i>= nums.size()) return 0;
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int pick = 0 , dont = 0;
        dont = helper(nums , i+1 , prev);
        
        if(prev== -1) pick = 1 + helper(nums , i+1 , i);
        else if(nums[prev] < nums[i]) pick = 1 + helper(nums , i+1 , i);
        
        return dp[i][prev+1] = max(pick , dont);
    }
};