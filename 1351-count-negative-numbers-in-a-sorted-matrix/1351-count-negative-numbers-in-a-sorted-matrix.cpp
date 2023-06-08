class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        
        int till = -1 , ans = 0;
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j > till ; j--){
                if(grid[i][j] >= 0){
                    till = j;
                    break;
                }
                else ans++;
            }
        }
        
        return ans;
    }
};