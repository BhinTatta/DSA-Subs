class Solution {
public:
    int n;
    int dp[301][11];
    
    int minDifficulty(vector<int>& job, int d) {
        n = job.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        int ans = helper(job , 0 , d);
        return ans;
    }
    
    int helper(vector<int>&job , int i , int d){
        if(i>=n && d==0) return 0;
        if(i>=n || d==0) return INT_MAX;
        
        if(dp[i][d]!=-1) return dp[i][d];
        
        int curr = job[i];
        int ans = INT_MAX;
        for(int j = i ; j < n ; j++){
            curr = max(curr , job[j]);
            int temp = helper(job , j+1 , d-1);
            if(temp!=INT_MAX){
                ans = min(ans , temp + curr );
            }
        }
        
        return dp[i][d] = ans;
    }
};