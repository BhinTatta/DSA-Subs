class Solution {
public:
    int drow[8] = {-1,-1,-1,0,1,1,1,0};
    int dcol[8] = {-1,0,1,1,1,0,-1,-1};
    int n;
    bool valid(vector<vector<int>>& grid , int r , int c){
        if(r<0 || c<0 || r==n || c==n) return 0;
        if(grid[r][c]==1) return 0;
        return 1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int ans = 0;
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size-->0){
                auto curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
                
                for(int i = 0 ; i < 8 ; i++){
                    for(int j = 0 ; j < 8 ; j++){
                        int r = row + drow[i];
                        int c = col + dcol[j];
                        
                        if(valid(grid,r,c)){
                            if(r==n-1 && c == n-1){
                                return ans+1;
                            }
                            grid[r][c] = 1;
                            q.push({r,c});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};