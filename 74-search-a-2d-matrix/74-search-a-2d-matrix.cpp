class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int key = target;
        int rownum = -1;
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        
        int rlow = 0 ;
        int rhigh = row;
        while(rlow <= rhigh){
            int rmid = (rhigh + rlow)/2;
            if(key<= matrix[rmid][col] && key>= matrix[rmid][0]){
                rownum = rmid;
                break;
            }
            
            else if(key < matrix[rmid][0]) rhigh = rmid-1;
            
            else if(key > matrix[rmid][col]) rlow = rmid+1;
        }
        
        if(rownum == -1) return false;
        
        int clow = 0;
        int chigh = col;
        
        while(clow<= chigh){
            int cmid = (clow+chigh)/2;
            
            if(matrix[rownum][cmid]==key) return true;
            
            else if(key < matrix[rownum][cmid]) chigh = cmid-1;
            
            else if(key > matrix[rownum][cmid]) clow = cmid + 1;
        }
        
        return false;
    }
};