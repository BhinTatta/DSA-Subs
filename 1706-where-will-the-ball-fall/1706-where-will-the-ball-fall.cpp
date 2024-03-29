class Solution {
private:
    vector<vector<int>> dp;
public:
    int n , m;
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        vector<int> ans;
        
        dp.resize(101,vector<int>(101,-2));
        
        for(int i = 0 ; i < m ; i++){
            int x = helper(grid , 0 , i );
            ans.push_back(x);
        }
        return ans;
    }
    
    int helper(vector<vector<int>>& grid , int r , int c ){
        if(r==n) return c;
        if(c<0 || c>=m) return -1;
        int ans = -1;
        
        if(dp[r][c]!=-2) return dp[r][c]; 
        
        if(grid[r][c]==1){
            if(c<m-1 && grid[r][c+1]==1){
                ans = helper(grid , r+1 , c+1);
            }
        }
        else if(grid[r][c]==-1){
            if(c>0 && grid[r][c-1]==-1){
                ans = helper(grid , r+1 , c-1);
            }
        }
        
        return dp[r][c] = ans;
    }
};











