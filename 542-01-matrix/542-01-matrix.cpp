class Solution {
public:
    int m,n;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,-1,0,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();     
        queue<pair<int,int>> q;
        
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        
        while(!q.empty()){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(int x = 0 ; x < 4 ; x++){
                    int row = r+drow[x];
                    int col = c+dcol[x];
                    if(row>=0 && row<m && col >=0 && col<n && mat[row][col]==-1){
                        mat[row][col] = mat[r][c]+1;
                        q.push({row,col});
                    }
                }           
        }
        
        return mat;
    }
};