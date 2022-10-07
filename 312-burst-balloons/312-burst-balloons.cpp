class Solution {
public:
    int n;
    int dp[501][501];
    int maxCoins(vector<int>& arr) {
        memset(dp,0,sizeof(dp));
        n = arr.size();
        arr.insert(arr.begin() , 1);
        arr.push_back(1);
        
        for(int i = n ; i >= 1 ; i--){
            for(int j = 1 ; j <= n ; j++){
                if(i>j) continue;
                if(i==j) dp[i][j] = arr[i]*arr[i-1]*arr[i+1];
                else{
                    int maxi = 0;
                    for(int k = i ; k <= j ; k++){
                        int curr = arr[k]*arr[i-1]*arr[j+1];
                        int cost = dp[i][k-1] + dp[k+1][j] +curr;
                        maxi = max(cost,maxi);           
                    }
                    dp[i][j] = maxi;
                }
            }
        }
        
        return dp[1][n];
    }

};