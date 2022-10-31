class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<int> row = mat[0];
        
        for(int i = 1 ; i < n ; i++){
            int x = mat[i][0];
            row.pop_back();
            row.insert(row.begin() , x);
            if(row != mat[i]) return false;
        }
        
        return true;
    }
};