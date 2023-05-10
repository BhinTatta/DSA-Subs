class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        int count = 0 , m = q.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        vector<int> ans;
        
        for(int i = 0 ; i < m ; i++){
            int ind = q[i][0] , c = q[i][1];
            
            int l = ind-1>=0 ? dp[ind-1] : 0;
            int r = ind+1<n ? dp[ind+1] : 0;
            
            if(dp[ind] && l==dp[ind]) count--;
            if(dp[ind] && r==dp[ind]) count--;
            
            dp[ind] = c;
            
            if(l==dp[ind]) count++;
            if(r==dp[ind]) count++;

            ans.push_back(count);
        }
        
        return ans;
    }
};