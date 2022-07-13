class Solution {
public:
    int n , m;
    vector<vector<bool>> atl , psf;
    vector<vector<int>> ans;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        psf = vector<vector<bool>>(n, vector<bool>(m , false));
        atl = vector<vector<bool>>(n, vector<bool>(m , false));
        for(int i = 0 ; i < n ; i++){
            dfs(grid , psf , i , 0);
            dfs(grid , atl , i , m-1);
        }
        for(int i = 0 ; i < m ; i++){
            dfs(grid , psf , 0 , i);
            dfs(grid , atl , n-1 , i);
        }
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(atl[i][j] && psf[i][j]){
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &grid , vector<vector<bool>> &sea , int r , int c){
        if(sea[r][c]==true) return;
        
        sea[r][c]=true;
        
        
        if(r-1>=0 && grid[r-1][c] >= grid[r][c]) dfs(grid , sea , r-1, c);
        if(r+1<n && grid[r+1][c] >= grid[r][c]) dfs(grid , sea , r+1, c);
        if(c-1>=0 && grid[r][c-1] >= grid[r][c]) dfs(grid , sea , r, c-1);
        if(c+1<m && grid[r][c+1] >= grid[r][c]) dfs(grid , sea , r, c+1);
        
    }
};




