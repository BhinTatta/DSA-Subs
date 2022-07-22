class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if( abs(target) > sum || (sum+target)%2==1 ) return 0;
        
        sum = (sum + target) / 2;
        
        vector<int> dp( sum +1 , 0);
        dp[0] = 1;
        
        for(int i = 1 ; i < n+1 ; i++){
            vector<int> newdp(sum+1);
            for(int j = 0 ; j < sum+1 ; j++){
                if(nums[i-1] > j) newdp[j] = dp[j];
                else{
                    newdp[j] = dp[j] + dp[j - nums[i-1]];
                }
            }
            dp = newdp;
        }
        
        return dp[sum];
    }
};