class Solution {
public:
    int n , m;
    string word;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    int vis[7][7];

    bool exist(vector<vector<char>>& grid, string words) {
        word = words;
        n = grid.size();
        m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==words[0]){
                    memset(vis,0,sizeof(vis));
                    bool ans = helper(grid,i,j,0);
                    if(ans) return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& grid , int i , int j , int len){
        if(len==word.length()-1) return true;
        bool ans = false;
        vis[i][j]=1;
        char req = word[len+1];

        for(int x = 0 ; x < 4 ; x++){
            int r = i + drow[x] , c = j + dcol[x];
            if(r>-1 && r<n && c>-1 && c<m && vis[r][c]==0 && grid[r][c]==req){
                ans = helper(grid , r , c , len+1);
                if(ans) return true;
            }
        }
        vis[i][j]=0;
        return ans;
    }
};