class Solution {
private:
    int mod = 1e9+7;
    int dp[14][(1 << 14) + 5];

public:
    int specialPerm(vector<int>& nums) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < nums.size() ; i++){
            int mask = (1<<i);
            int prev = nums[i];
            ans += helper(nums , i , mask)%mod;
            ans = ans%mod;
        }
        return ans;
    }
    
    int helper(vector<int> &nums , int prev_i , int mask){
        if( mask == (1 << nums.size()) - 1){
            return 1;
        }
        //cout<<prev_i<<" ";
        if(dp[prev_i][mask]!=-1){
            return dp[prev_i][mask];
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if((mask & (1<<i)) == 0 ){
                int curr = nums[i];
                int prev = nums[prev_i];
                if(curr%prev==0 || prev%curr==0){
                    int new_mask = mask | (1<<i);
                    ans += helper(nums , i , new_mask)%mod;
                    ans = ans%mod;
                }
            }
        }
        
        return dp[prev_i][mask] = ans%mod;
    }
};









