class Solution {
public:
    int n , m;
    int drow[4] = { -1, 0, 1, 0 };
    int dcol[4] = { 0, 1, 0, -1 };
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        for(int i = 0 ; i < m ; i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        for(int i = 0 ; i < n ; i++){
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[m-1][i]=='O') dfs(board,m-1,i);
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j ++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Z') board[i][j]='O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board , int r, int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            board[curr.first][curr.second]='Z';
            for(int i = 0 ; i < 4 ; i++){
                int row = curr.first + drow[i];
                int col = curr.second + dcol[i];
                //cout<<row<<" "<<col<<endl;
                if(isvalid(board,row,col)){
                    //cout<<row<<" "<<col<<endl;
                    board[row][col]='Z';
                    q.push({row,col});
                }
            }
        }
        
    }
    
    bool isvalid( vector<vector<char>>& board,int r , int c){
        if(r<0 || r>=m || c<0 || c>=n) return false;
        if(board[r][c]=='O'){
            //cout<<r<<" "<<c<<endl;
            return true;
        }
        return false;
    }
};










