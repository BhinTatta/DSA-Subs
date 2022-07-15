class Solution {
public:
    int n;
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        vector<vector<int>> dp ( 201 , vector<int> (20002 , -1));
        for(int i = 0 ; i < n ; i ++ ){
            sum += nums[i];
        }
        if(sum%2==1) return false;
        sum /= 2;
        
        return helper(nums , sum , 0 , dp);
    }
    
    bool helper(vector<int> &nums , int sum , int  i , vector<vector<int>> &dp){
        if(i >= n || sum <= 0){
            bool ans;
            sum==0 ? ans = true : ans = false;
            return ans;
        }
        
        bool ans;
        
        if(dp[i][sum]!=-1){
            dp[i][sum]==1 ? ans = true : ans = false;
            return ans;
        }
        
        if(nums[i] > sum){
            ans = helper(nums , sum , i+1 , dp); 
        }
        else{
            bool take = helper(nums , sum - nums[i] , i+1 , dp);
            bool donttake = helper(nums , sum , i+1 , dp);
            ans = take || donttake;
        }
        ans == true ? dp[i][sum] = 1 : dp[i][sum] = 0;
        return ans;
    }
};