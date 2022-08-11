class Solution {
public:
    int n;
    int dp[501][501];
    int maxCoins(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        n = arr.size();
        vector<int> nums = {1};
        for(int x : arr) nums.push_back(x);
        nums.push_back(1);
        return helper(nums,1,n);
    }
    
    int helper(vector<int>&nums , int i , int j){
        if(i>j) return 0;
        if(i==j){
            return nums[i]*nums[i-1]*nums[j+1];          
        };
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = 0 , brek = 0;
        for(int k = i ; k <= j ; k++){
            int curr = nums[k]*nums[i-1]*nums[j+1];
            int cost = helper(nums,i,k-1)+helper(nums,k+1,j)+curr;
            maxi = max(cost,maxi);           
        }
        //cout<<nums[brek]<<endl;
        return dp[i][j] = maxi;
    }
};