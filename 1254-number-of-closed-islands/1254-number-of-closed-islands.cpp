class Solution {
public:
    int m , n , ans = 0;
    int drow[4] = {-1 , 0 , 1 , 0};
    int dcol[4] = {0 , 1 , 0 , -1};
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 1 ; i < m-1 ; i++){
            for(int j = 1 ; j < n-1 ; j++){
                if(grid[i][j]==0) bfs(grid,i,j);
            }
        }
        return ans;
    }
    
    void bfs(vector<vector<int>>& grid , int r , int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        bool flag = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            grid[curr.first][curr.second]=1;
            if(curr.first==0 || curr.first==m-1 || curr.second==0 || curr.second==n-1 ) flag = false;
            for(int i = 0 ; i < 4 ; i++){
                int myrow = drow[i] + curr.first;
                int mycol = dcol[i] + curr.second;
                if(myrow < 0 || myrow >=m || mycol<0 || mycol>=n) continue;
                else if(grid[myrow][mycol]==0) q.push({myrow,mycol});
            }
        }
        if(flag) ans++;
    }
    
    
};









