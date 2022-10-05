class Solution {

public:
    int dp[101][101];
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin() , 0);
        cuts.push_back(n);
        
        sort(cuts.begin() , cuts.end());
        memset(dp,-1,sizeof(dp));
        return helper(cuts,1,c);
    }
    
    int helper(vector<int>&cuts , int i , int j){
        //cout<<i<<" "<<j<<endl;
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for(int x = i ; x <= j ; x++){
            int cost = cuts[j+1] - cuts[i-1] + helper(cuts, i , x-1) + helper(cuts ,x+1 , j);
            mini = min(mini , cost);
        }
        
        return dp[i][j] = mini;
    }
};