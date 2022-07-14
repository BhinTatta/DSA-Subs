class Solution {
public:
    int n = 0 , m = 0;
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int island = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(grid[i][j]=='1'){
                    island++;
                    bfs(grid , i , j);
                }
            }
        }
        return island;
    }
    
    void bfs(vector<vector<char>>& grid , int r , int c ){
        queue<pair<int,int>> q;
        q.push(make_pair(r,c));
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            zeromaker(grid , curr.first , curr.second , q);
        }
    }
    
    void zeromaker(vector<vector<char>>& grid , int r , int c , queue<pair<int,int>> &q){
        grid[r][c]='0';
        
        if(r-1>=0 && grid[r-1][c]=='1'){
            q.push(make_pair(r-1,c));
            grid[r-1][c]='0';
        }
        if(r+1<n && grid[r+1][c]=='1'){
            q.push(make_pair(r+1,c));
            grid[r+1][c]='0';
        }
        if(c-1>=0 && grid[r][c-1]=='1'){
            q.push(make_pair(r,c-1));
            grid[r][c-1]='0';
        }
        if(c+1<m && grid[r][c+1]=='1'){
            q.push(make_pair(r,c+1));
            grid[r][c+1]='0';
        }
        
    }
};