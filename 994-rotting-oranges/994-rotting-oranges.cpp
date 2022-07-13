class Solution {
public:
    int n , m , total=0 , time = 0 , done=0;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j ++){
                if(grid[i][j]==1) total++;
                if(grid[i][j]==2) q.push(make_pair(i,j));
            }
        }
        
        helper(grid, q );
        //cout<<total <<" - "<<done<<endl;
        if(total==done) return time-1;
        return -1;
        
    }
    
    void helper(vector<vector<int>>& grid , queue<pair<int,int>> q){
        
        time++;
        queue<pair<int,int>> newq;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int row = curr.first;
            int col = curr.second;
            rot(row,col,grid,newq);
        }
        
        if(!newq.empty()) helper(grid , newq);
    }
    
    void rot(int row, int col , vector<vector<int>>& grid , queue<pair<int,int>> &q){
        //cout<<row<<" "<<col<<endl;
        if(row-1 >= 0 && grid[row-1][col]==1){          
            grid[row-1][col]=2;
            done++;
            q.push(make_pair(row-1,col));   
            //cout<<"up"<<endl;
        }
        if(row+1 < n && grid[row+1][col]==1){
            //cout<<"down"<<endl;
            grid[row+1][col]=2;
            done++;
            q.push(make_pair(row+1,col)); 
        }
        if(col-1 >= 0 && grid[row][col-1]==1){          
            grid[row][col-1]=2;
            done++;
            q.push(make_pair(row,col-1)); 
            //cout<<"left"<<endl;
        }
        if(col+1 < m && grid[row][col+1]==1){          
            grid[row][col+1]=2;
            done++;
            q.push(make_pair(row,col+1));  
            //cout<<"right"<<endl;
        }
        return;
    }
};