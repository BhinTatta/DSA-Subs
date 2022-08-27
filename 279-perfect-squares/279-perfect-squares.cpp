class Solution {
public:
    int size;
    int numSquares(int n) {
        vector<int> nums;
        int num = 1;
        while(num*num<=n){
            //cout<<num*num<<endl;
            nums.push_back(num*num);
            num++;
        }
        size = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(size+1 , -1));
        return helper(nums,n,0,dp);
    }
    
    int helper( vector<int> &nums , int sum , int i , vector<vector<int>> &dp ){
        if(sum==0) return 0;
        if(i>=size) return INT_MAX-1;
        
        if(dp[sum][i]!=-1) return dp[sum][i];
        
        int take = INT_MAX, dont = INT_MAX;
        
        if(nums[i]<=sum){
            take = 1 + helper(nums , sum - nums[i] , i , dp);
            dont = helper(nums , sum , i+1 , dp);
        }
        else dont = helper(nums , sum , i+1 , dp);
        
        return dp[sum][i] = min(take,dont);
    }
};








