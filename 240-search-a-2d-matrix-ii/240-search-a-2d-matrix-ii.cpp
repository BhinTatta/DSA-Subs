class Solution {
public:
    int m , n;
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        m = mat.size()-1;
        n = mat[0].size()-1;        
        int r = 0 , c = n;        
        if(k < mat[0][0] || k > mat[m][n]) return false;        
        while( isbound(r,c) ){
            int curr = mat[r][c];
            if( k == curr ) return true;
            k > curr ? r++ : c-- ;
        }        
        return false;
    }
    
    bool isbound(int a , int b){
        if(a > m || a < 0 || b > n || b < 0) return false;
        return true;
    }
};