class Solution {
public:
    int dp[100001][2][2];
    
    int maxProfit(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums , 0 , 0 , false);
    }
    
    int helper(vector<int> &nums , int i , int trans , bool state){
        if(i>=nums.size() || trans==2) return 0;
        
        if (dp[i][trans][state]!=-1) return dp[i][trans][state];
        
        int buy = 0 , sell = 0 , dont = 0;
        if(state){
            sell = helper(nums , i+1 , trans+1 , !state) + nums[i];
            dont = helper(nums , i+1 , trans , state);
        }
        else{
            buy = helper(nums , i+1 , trans , !state) - nums[i];
            dont = helper(nums , i+1 , trans , state);
        }
        
        return dp[i][trans][state] = max(dont , max(buy,sell));
        
    }
};