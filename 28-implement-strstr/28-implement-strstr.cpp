class Solution {
public:
    int strStr(string hay, string need) {
        int n = hay.size();
        int m = need.size();
        if(n==0 || m==0) return -1;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(hay[i-1]==need[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j]==m){
                        //cout<<hay[i-1]<<" "<<dp[i][j];
                        return i-m;
                    }
                }
                else dp[i][j]=0;
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return -1;
    }
};