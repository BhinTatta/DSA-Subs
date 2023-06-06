class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long ans = 0;
        int r = n , c = n;
        vector<int> row(n,0) , col(n,0);
        
        for(int i = q.size()-1 ; i >= 0 ; i--){
            int type = q[i][0] , id = q[i][1] , val = q[i][2];
            
            if(type){
                if(col[id]) continue;
                col[id]++;
                ans += val * r;
                c--;
            }
            else{
                if(row[id]) continue;
                row[id]++;
                ans += val * c;
                r--;
            }
            
        }
        
        return ans;
    }
};