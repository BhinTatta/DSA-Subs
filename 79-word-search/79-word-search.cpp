class Solution {
public:
    int m , n;
    bool exist(vector<vector<char>>& grid, string word) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<int>> vis(m , vector<int>(n,0));
        
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(grid[i][j]==word[0]){
                    vis[i][j]=1;
                    if(dfs(grid,word,vis,i,j,1)) return true;
                    vis[i][j]=0;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& grid, string &word, vector<vector<int>> &vis , int row , int col , int x  ){
        if(x == word.length()) return true;
        vis[row][col]=1;
        char req = word[x];
        bool ans = false;
        
        if(row-1 >=0 && grid[row-1][col] == req && vis[row-1][col]!=1) ans = ans || dfs(grid,word,vis,row-1,col,x+1);
        if(ans) return true;
        if(row+1 < m && grid[row+1][col] == req && vis[row+1][col]!=1) ans = ans || dfs(grid,word,vis,row+1,col,x+1);
        if(ans) return true;
        if(col-1 >=0 && grid[row][col-1] == req && vis[row][col-1]!=1) ans = ans || dfs(grid,word,vis,row,col-1,x+1);
        if(ans) return true;
        if(col+1 < n && grid[row][col+1] == req && vis[row][col+1]!=1) ans = ans || dfs(grid,word,vis,row,col+1,x+1);
        vis[row][col] = 0;
        return ans;
    }
};