class Solution {
public:
    int n , m;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dist(n , vector<int>(m,INT_MAX));
        //dist[0][0] = 0;
        priority_queue<vector<int>> pq;
        pq.push( {0 , 0 , 0} );
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = -curr[0] , x = curr[1] , y = curr[2];
            int val = grid[x][y];
            if(d>dist[n-1][m-1]) continue;
            //if(x==n-1 && y==m-1) return dist[x][y];
            for(int i = 0 ; i < 4 ; i++){
                
                    int r = x + drow[i];
                    int c = y + dcol[i];
                    
                    if( r>-1 && c>-1 && r<n && c<m ){
                        int cost = max(d , abs(grid[x][y] - grid[r][c]) );
                        
                        if(cost < dist[r][c]){
                            pq.push( {-cost , r , c} );
                            dist[r][c] = cost;
                        }
                        
                        //if(r==n-1 && c==m-1) return dist[r][c];
                    }
                
            }
        }
        return dist[n-1][m-1]==INT_MAX ? 0 : dist[n-1][m-1];
    }
};