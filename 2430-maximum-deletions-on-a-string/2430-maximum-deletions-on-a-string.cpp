class Solution {
public:
    int n;
    int dp[4001];
    int deleteString(string s) {
        //memset(dp , -1 , sizeof(dp));
        n = s.length();
        int ans = helper(s,0);
        return ans;
    }
    
    int helper(string &s , int i){
        if(i >= n) return 0;
        if(dp[i]!=0) return dp[i];
        int len = (n-i)/2;
        int ans = 1;
        for(int j = 1 ; j <= len ; j++){
            //cout<<s.substr(i , j)<<" - "<<s.substr(i+j ,j )<<endl;
            if(s.compare(i, j, s, i + j, j) == 0){
                ans = max(ans , 1+helper(s , i+j));
            }
        }
        return dp[i] = ans;
    }
};