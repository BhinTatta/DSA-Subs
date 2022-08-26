class Solution {
public:
    int m , n;
    
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int marker = -1;
        while( find(matrix , marker) ){
            marker--;
        }
        //cout<<marker<<endl;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j]==0) fill(matrix,i , j , marker);
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j]==marker) matrix[i][j]=0;
            }
        }
    }
    
    void fill(vector<vector<int>>& matrix , int r , int c , int k){
        for(int i = 0 ; i < n ; i++) if(matrix[r][i] != 0) matrix[r][i] = k;
        for(int i = 0 ; i < m ; i++) if(matrix[i][c] != 0) matrix[i][c] = k;
    }
    
    bool find(vector<vector<int>>& matrix , int k){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == k) return true;
            }
        }
        return false;
    }
};