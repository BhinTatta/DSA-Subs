class Solution {

public:
    #define ll long long int
    
    ll dp[101][101][101];
    int n , m;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = robot.size();
        m = factory.size();
        memset(dp,-1,sizeof(dp));
        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());
        
        ll  ans = helper(0,0,0,robot,factory);
        return ans;
    }
    
    ll helper(int i , int j , int k ,vector<int>& robot, vector<vector<int>>& fact ){
        if(i>=n) return 0;
        if(j>=m) return 1e16;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        ll dont = helper(i,j+1,0,robot,fact);
        ll fix = 1e16;
        if(k<fact[j][1]) fix = abs(robot[i] - fact[j][0]) + helper(i+1,j,k+1,robot,fact);
        
        
        return dp[i][j][k] = min(dont,fix);
    }
};