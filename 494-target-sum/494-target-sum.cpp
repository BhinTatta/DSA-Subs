class Solution {
public:
    int ans = 0;
    int n;
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>> dp( n+1 , vector<int> (2002 , -1) );
        
        return helper(nums , 0 , 0 , target , dp);
    }
    
    int helper(vector<int>& nums , int i , int sum , int target , vector<vector<int>> &dp){
        if(i >= n){
            if(sum==target) return 1;
            else return 0;
        }
        
        if(dp[i][sum+1000] != -1) return dp[i][sum+1000];
        
        int plus = helper(nums , i+1 , sum+nums[i] , target , dp);
        int minus = helper(nums , i+1 , sum-nums[i] , target , dp);
        
        return dp[i][sum+1000] = plus + minus;
    }
};