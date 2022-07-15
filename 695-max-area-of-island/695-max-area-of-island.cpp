class Solution {
public:

    int n = 0 , m = 0;
    int maxarea = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int island = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(grid[i][j]==1){
                    island++;
                    bfs(grid , i , j);
                    //cout<<"----------- island----------"<<endl;
                }
            }
        }
        return maxarea;
    }
    
    void bfs(vector<vector<int>>& grid , int r , int c ){
        queue<pair<int,int>> q;
        q.push(make_pair(r,c));
        int area = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            zeromaker(grid , curr.first , curr.second , q , area);
        }
        maxarea = max (area , maxarea);
    }
    
    void zeromaker(vector<vector<int>>& grid , int r , int c , queue<pair<int,int>> &q , int &area){
        //cout<<r<<" "<<c<<"  @"<<endl;
        grid[r][c]=0;
        //area++;
        if(r-1>=0 && grid[r-1][c]==1){
            q.push(make_pair(r-1,c));
            grid[r-1][c]=0;
            area++;
            //cout<<r<<" "<<c<<"  up"<<endl;
        }
        if(r+1<n && grid[r+1][c]==1){
            q.push(make_pair(r+1,c));
            grid[r+1][c]=0;
            area++;
            //cout<<r<<" "<<c<<"  down"<<endl;
        }
        if(c-1>=0 && grid[r][c-1]==1){
            q.push(make_pair(r,c-1));
            grid[r][c-1]=0;
            area++;
            //cout<<r<<" "<<c<<"  left"<<endl;
        }
        if(c+1<m && grid[r][c+1]==1){
            q.push(make_pair(r,c+1));
            grid[r][c+1]=0;
            area++;
            //cout<<r<<" "<<c<<"  down"<<endl;
        }
        
    }
};