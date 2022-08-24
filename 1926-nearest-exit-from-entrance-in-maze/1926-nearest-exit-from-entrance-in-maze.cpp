class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,-1,0,1};
    
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int n = grid.size();
        int m = grid[0].size();
        
        int x = entrance[0];
        int y = entrance[1];
        
        queue<pair<int,int>> q;
        q.push({x,y});
        
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            while(size-->0){
                auto curr = q.front();
                q.pop();
                int r = curr.first , c = curr.second;
                grid[r][c] = '+';
                for(int i = 0 ; i < 4 ; i++){
                    int row = r + drow[i];
                    int col = c + dcol[i];
                    //if(row==0 || col==0 || row ==n-1 || col == m-1 && grid[row][col]=='.') return steps;
                    if(row>=0 && col>=0 && row <n && col < m && grid[row][col]=='.'){
                        if( row==0 || col==0 || row ==n-1 || col == m-1 ) return steps;
                        else{
                            q.push({row,col});
                            grid[row][col]='+';
                        }
                    }
                }
            }
            steps++;
        }
           
                       
        return -1;
    }
};