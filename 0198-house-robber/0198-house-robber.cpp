class Solution {
private:
    int n;
    int dp[101];
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(nums , 0);
    }
    
    int helper(vector<int> &nums , int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + helper(nums , i+2);
        int dont = helper(nums , i+1);
        
        return dp[i] = max(rob,dont);
    }
};