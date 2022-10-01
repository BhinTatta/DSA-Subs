class Solution {
public:
    int n;
    int dp[101];
    int numDecodings(string s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0') return 0;
        solver(s , 0);
        return dp[0];
    }
    
    int solver(string &s , int i){
        if(i >= n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int one = 0 , two = 0;
        if(s[i]!='0') one = solver(s,i+1);
        if(i+1<n && (s[i]=='1')){
            two = solver(s,i+2);
        }
        if(i+1<n && (s[i]=='2' && (s[i+1]-'0' <= 6))){
            two = solver(s,i+2);
        }
        return dp[i]=one+two;
    }
};