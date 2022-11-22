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
        vector<vector<int>> dp(size+1 , vector<int>(n+1 , INT_MAX-1));
        dp[0][0] = 0;
        for(int i = 1 ; i < size+1 ; i++){
            for(int j = 0 ; j < n+1 ; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j-nums[i-1]]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
                
        return dp[size][n];
    }
    
};








