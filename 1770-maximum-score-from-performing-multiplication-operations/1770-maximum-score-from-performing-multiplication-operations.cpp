class Solution {
public:
    int dp[1001][1001];
    int maximumScore(vector<int>& nums, vector<int>& mulp) {
        for(int i = 0 ; i < 1001 ; i++){
            for(int j = 0 ; j < 1001 ; j++){
                dp[i][j] = -1e9; 
            }
        }
        int n = nums.size();
        int m = mulp.size();

        return helper(nums, mulp , 0 , 0 , n-1);
    }
    
    int helper(vector<int>& nums, vector<int>& mulp , int i , int l , int r){
        if(i>=mulp.size() || l>r) return 0;
        
        if(dp[i][l]!=-1e9) return dp[i][l];
        
        int x = mulp[i];
        int a = 0 , b = 0;
        
        a = x * nums[l] + helper(nums,mulp,i+1,l+1,r);
        b = x * nums[r] + helper(nums,mulp,i+1,l,r-1);
        
        return dp[i][l] = max(a,b);
    }
};