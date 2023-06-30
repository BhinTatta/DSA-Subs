class Solution {
private:
    int row , col;
    
    int drow[4] = {0,1,0,-1};
    int dcol[4] = {1,0,-1,0};
public:
    int latestDayToCross(int r1, int c1, vector<vector<int>>& cells) {
        row = r1 , col = c1;
        
        int l = 0 , r = cells.size()-1;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            bool cross = helper(mid , cells);
            
            if(cross){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
            
        }
        
        return ans;
    }
    
    bool helper(int day , vector<vector<int>>& cells){
        vector<vector<int>> grid(row , vector<int>(col,1));
        for(int i = 0 ; i < day ; i++){
            int r = cells[i][0]-1 , c = cells[i][1]-1;
            grid[r][c] = 0;
        }        
        return bfs(grid);
    }
    
    
    bool bfs(vector<vector<int>> grid){
        //cout<<grid.size()<<" + "<<grid[0].size()<<endl;
        queue<pair<int,int>> q;
        
        for(int i = 0 ; i < col ; i++){
            if(grid[0][i]==1){
                q.push({0,i});
                grid[0][i] = 0;
            }        
        }
        
        while(!q.empty()){
            int size = q.size();
            while(size-->0){
                auto curr = q.front();
                q.pop();
                
                int r = curr.first , c = curr.second;
                grid[r][c]=0;
                
                if(r==row-1) return true;
                //cout<<r<<" -- "<<c<<endl;
                for(int i = 0 ; i < 4 ; i++){
                    int newrow = r + drow[i] , newcol = c + dcol[i];
                    if(valid(newrow,newcol) && grid[newrow][newcol]==1){
                        if(newrow==row-1) return true;
                        q.push({newrow,newcol});
                        //cout<<newrow<<" "<<newcol<<endl;
                        grid[newrow][newcol] = 0;
                    }
                }
            }
        }
        
        return false;
    }
    
    
    bool valid(int r , int c){
        return (r<row && r>=0) && (c<col && c>=0);
    }
    
    
    
    
    
    
    
    
    
    
    
};