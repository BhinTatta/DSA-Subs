class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , 0);
        for(int i = n-2 ; i >= 0 ; i--){
            int mini = INT_MAX-1;
            for(int j = 1 ; j <= nums[i] && i+j < n  ; j++){
                int curr = 1 + dp[i+j];
                mini = min(mini , curr);
            }
            dp[i]=mini;
        }
        return dp[0];
    }

};