class Solution {
public:
    int n;
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n,-1);
        return dfs(nums , 0 , dp);
    }
    
    bool dfs(vector<int> &nums , int i , vector<int>&dp){
        if(i >= n) return false;
        if(i == n-1 ) return true;
        if(nums[i]==0) return false;
        
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        for(int j = 1 ; j <= nums[i] ; j++){
            bool curr = dfs(nums , i+j , dp);
            if(curr){
                return dp[i] = true;
            }
        }
        
        return dp[i] = false;
    }
};