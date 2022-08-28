class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            vector<int> temp;
            int j = i , k = 0;
            while(j<n && k<m){
                temp.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(temp.begin() , temp.end());
            j = i , k = 0;
            while(j<n && k<m){
                mat[j][k] = temp[k];
                j++;
                k++;
            }
        }
        for(int i = 1 ; i < m ; i++){
            vector<int> temp;
            int j = 0 , k = i;
            while(j<n && k<m){
                temp.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(temp.begin() , temp.end());
            j = 0 , k = i;
            while(j<n && k<m){
                mat[j][k] = temp[j];
                j++;
                k++;
            }
        }
            
        return mat;
    }
};