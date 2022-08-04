class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , -1);
        return jumper(nums , n , 0 , dp) - 1;
    }
    
    int jumper(vector<int>&nums , int n , int i , vector<int> &dp){
        if(i>=n-1) return 1;
        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX-1;
        for(int j = 1 ; j <= nums[i] ; j++){
            int curr = 1 + jumper(nums , n , i+j , dp);
            mini = min(mini , curr);
        }
        return dp[i] = mini;
    }
};