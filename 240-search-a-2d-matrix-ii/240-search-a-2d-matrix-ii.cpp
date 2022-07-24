class Solution {
public:
    int m , n;
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        m = mat.size()-1;
        n = mat[0].size()-1;        
        int r = 0 , c = n;        
        if(k < mat[0][0] || k > mat[m][n]) return false;        
        while( r <= m && c >= 0 ){
            int curr = mat[r][c];
            if( k == curr ) return true;
            k > curr ? r++ : c-- ;
        }        
        return false;
    }
};