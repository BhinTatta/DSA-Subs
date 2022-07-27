class Solution {
public:
    int n;
    bool canJump(vector<int>& nums) {
        n = nums.size();
        reverse(nums.begin() , nums.end());
        vector<bool> dp(n,false);
        dp[0] = true;
        
        for(int i = 1 ; i < n ; i++){
            int x = 1;
            while(i-x>=0 && x <= nums[i]){
                if(dp[i-x]){
                    dp[i]= true;
                    break;
                }
                x++;
            }
        }
        return dp[n-1];
    }

};