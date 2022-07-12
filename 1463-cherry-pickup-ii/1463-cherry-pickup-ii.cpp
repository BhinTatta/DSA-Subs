class Solution {
public:
    int row , col;
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector< vector< vector<int> > > dp(row , vector< vector<int> > (col, vector<int> (col,-1) ) );
        int ans = helper(grid , 0 , 0 , col-1,dp);
        return ans;
    }
    
    int helper(vector<vector<int>>& grid , int i , int j1 , int j2, vector< vector< vector<int> > > &dp){
        if((j1<0 || j1> col-1) || (j2<0 || j2 >col-1)) return -1e5;
        //cout<<i <<" "<<j1 <<" "<<j2<<endl;
        if(i == row-1){
            if(j1==j2) return dp[i][j1][j2] = grid[i][j1];
            else{
                return dp[i][j1][j2] =  grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = 0;
        for(int d1 = -1 ; d1 <= 1 ; d1++){
            for(int d2 = -1 ; d2 <= 1 ; d2++){
                int curr = 0;
                if(j1 == j2){
                    curr = grid[i][j1] + helper(grid , i+1 , j1+d1 , j2+d2,dp);
                }
                else{
                    curr = grid[i][j1]+grid[i][j2] + helper(grid , i+1 , j1+d1 , j2+d2,dp);
                }
                
                maxi = max(maxi , curr);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
};