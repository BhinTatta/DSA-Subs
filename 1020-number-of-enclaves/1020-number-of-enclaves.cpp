class Solution {
public:
    int m , n;
    int drow[4] = {-1 , 0 , 1 , 0};
    int dcol[4] = {0 , 1 , 0 , -1};
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int tot_area = 0;
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0]==1) bfs(grid , i , 0);
            if(grid[i][n-1]==1) bfs(grid, i , n-1);
        }
        for(int i = 0 ; i < n ; i++){
            if(grid[0][i]==1)bfs(grid , 0 , i);
            if(grid[m-1][i]==1)bfs(grid, m-1 , i);
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1) tot_area++;
            }
        }
        return tot_area;
    }
    void bfs(vector<vector<int>>& grid , int r , int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            grid[curr.first][curr.second]=0;       
            for(int i = 0 ; i < 4 ; i++){
                int myrow = drow[i] + curr.first;
                int mycol = dcol[i] + curr.second;
                if(myrow < 0 || myrow >=m || mycol<0 || mycol>=n) continue;
                else if(grid[myrow][mycol]==1){
                    q.push({myrow,mycol});
                }
            }
        }
    }
};