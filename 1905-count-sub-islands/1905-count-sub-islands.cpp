class Solution {
public:
    int n , m;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        // for(int i = 0 ; i < m ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         grid2[i][j] = grid1[i][j]&&grid2[i][j];
        //     }
        // }
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid2[i][j]==1){
                    bool land = dfs(grid1 , grid2 , i , j);
                    
                    if(land){
                        ans++;
                        //cout<<i<<" "<<j<<endl;
                    }
                }
            }
        }
        return ans;
    }
    
    bool dfs(vector<vector<int>>& grid1 , vector<vector<int>>& grid2 , int r , int c){
        if(r<0 || r>m-1 || c<0 || c >n-1) return true;
        if(grid2[r][c]==0) return true;
        bool my = true;
        if(grid1[r][c]==0 && grid2[r][c]==1){
            grid2[r][c]=0;
            my = false;
        }
        grid2[r][c]=0;
        bool one = dfs(grid1, grid2,r-1,c);
        bool two = dfs(grid1,grid2,r+1,c);
        bool three = dfs(grid1,grid2,r,c-1);
        bool four = dfs(grid1,grid2,r,c+1);
        return my && one && two && three && four;
    }
};