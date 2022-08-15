class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int deleteAndEarn(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n+1 , -1);
        return helper(nums, 0  , dp);
    }
    
    int helper(vector<int>&nums , int i , vector<int> &dp){
        if(i>=n) return 0;
        int previ = i;
        if(dp[i]!=-1) return dp[i];
        int pick = 0, dont = 0;
        
        int sum = 0 , curr = nums[i];
        while(i < n && nums[i]==curr){
            sum+=nums[i];
            i++;
        }
        dont = helper(nums , i , dp);
        while(i<n && nums[i] == curr+1) i++;
        pick = sum + helper(nums , i ,dp);
        
        return dp[previ] = max(pick,dont);
    }
};