class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int dp[2001];
        memset(dp , 0 ,sizeof(dp));
        for(int i : arr){
            dp[i] = 1;
        }
        int i = 0;
        while(k > 0){
          i++; 
          if(dp[i]==0) k--;      
        }
        
        return i;
    }
};