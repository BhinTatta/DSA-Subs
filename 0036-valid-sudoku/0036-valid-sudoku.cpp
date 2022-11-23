class Solution {
public:
    bool valid(int row , vector<vector<char>>& board , vector<int> mrow , vector<int> mcol){
        bool flag = true;
        for(int i = 0 ; i < 9 ; i++){
            if(flag==false) return false;    
            if(board[row][i] != '.'){
                int x = int(board[row][i]  - '0' - 1);
                mrow[x]==1 ? flag = false : mrow[x]=1;
            }
            if(board[i][row] != '.'){
                int y = int(board[i][row]  - '0' - 1);
                mcol[y]==1 ? flag = false : mcol[y]=1;
            }
        }
        return flag;
    }
    
    bool matvalid(vector<vector<char>>& board , int row , int col ){
        bool flag = true;
        vector<int> mrow(9,-1);
        for(int i = 3*row ; i < 3*row+3 ; i++){
            for(int j = 3*col ; j < 3*col+3 ; j++){
                if(flag == false) return false;
                //cout<<i<<"-"<<j <<"   ";
                if(board[i][j] != '.'){
                    int x = int (board[i][j] - '0' - 1);
                    mrow[x]==-1 ?  mrow[x]=1 : flag = false ;
                }       
            }
            //cout<<endl;
        }
        return flag;    
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        bool flag = true;
        vector<int> mrow(9,-1);
        vector<int> mcol(9,-1);
        for(int i = 0 ; i < 9 ; i++){
            if(flag==true){
                flag = valid( i , board , mrow , mcol);
            }
        }
        if(flag==false) return false;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(flag==false) return false;
                flag = matvalid( board , i , j );
            }            
        }
        return flag;
    }
};