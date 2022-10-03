class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = i-1 ; j >= -1 ; j--){
                int dont = dp[i+1][j+1];
                int pick = 0;
                if(j==-1) pick = 1 + dp[i+1][i+1];
                else if(nums[j]<nums[i]) pick = 1 + dp[i+1][i+1];
                dp[i][j+1] = max(pick , dont);
            }
        }
        int ans = dp[0][0];
        return ans;
    }
    

};