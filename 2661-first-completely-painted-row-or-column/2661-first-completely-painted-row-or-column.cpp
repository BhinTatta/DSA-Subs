class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        
        vector<int> row(n,m) , col(m,n);
        
        unordered_map<int , vector<int>> mp;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        
        int mini = INT_MAX;
        
        for(int j = 0 ; j < arr.size() ; j++){
            int i = arr[j];
            int r = mp[i][0] , c = mp[i][1];
            
            row[r]--;
            col[c]--;
            if(row[r]==0 || col[c]==0) return j;

        }
        
        return mini;
    }
};