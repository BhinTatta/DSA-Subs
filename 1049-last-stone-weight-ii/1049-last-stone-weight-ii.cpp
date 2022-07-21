class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
	    for(int i = 0 ; i < n ; i ++){
	        sum += arr[i];
	    }
	    int total = sum;
	    sum /= 2;
	    
	    vector<vector<bool>> dp( n+1 , (vector<bool> (sum+1 , false)) );
	    
	    for(int i = 0 ; i < sum+1 ; i++) dp[0][i]=0;
	    for(int i = 0 ; i < n+1 ; i++) dp[i][0]=1;
	    
	    for(int i = 1 ; i < n+1 ; i++){
	        for(int j = 1 ; j < sum+1 ; j++){
	            if(arr[i-1] <= j){
	               bool dont = dp[i-1][j];
	               bool take = dp[i-1][j - arr[i-1]];
	               dp[i][j] = take || dont;
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    vector<int> temp;
	    for(int i = 0 ; i < sum+1 ; i++){
	        if(dp[n][i]) temp.push_back(i);
	    }
	    
	    int mini = INT_MAX;
	    for(int i = 0 ; i < temp.size() ; i++){
	        mini = min( mini , ( temp[i] , total - 2*temp[i]  ) );
	    }
	    
	    return mini;
    }
};