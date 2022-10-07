class Solution {

public:
    int dp[102][102];
    int minCost(int c, vector<int>& cuts) {
        int n = cuts.size();
        cuts.insert(cuts.begin() , 0);
        cuts.push_back(c);     
        sort(cuts.begin() , cuts.end());
        memset(dp,0,sizeof(dp));
        
        for(int i = n ; i >= 1 ; i--){
            for(int j = 1 ; j <= n ; j++){
                if(i>j) continue;
                
                int mini = INT_MAX;
        
                for(int x = i ; x <= j ; x++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][x-1] + dp[x+1][j];
                    mini = min(mini , cost);
                }
                dp[i][j] = mini;
                
            }
        }
        
        
        return dp[1][n];
    }
    

};