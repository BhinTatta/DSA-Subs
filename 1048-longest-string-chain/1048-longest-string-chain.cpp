class Solution {
public:
    
    static bool comp(const string &a , const string &b){
        return a.length() < b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        //memset(dp,-1,sizeof(dp));
        sort(words.begin() , words.end() , comp );
        int n = words.size();
        int ans = 1;
        int dp[n+1];
        for(int i = 0 ; i < n ; i++) dp[i]=1;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(can(words[i] , words[j]) && dp[i] < dp[j]+1  ){
                    dp[i] = dp[j]+1;
                }
            }
            ans = max(dp[i] , ans);
        }
        
        return ans;
    }
  
    bool can(string &a , string &b){
        int n = a.size() , m = b.size() , i = 0;
        if(m>=n || abs(n-m)!=1) return false; 
        
        while(i<m && a[i]==b[i]) i++;
        i++;
        while(i<n){
            if(a[i]!=b[i-1]) return false;
            i++;
        }
        
        return 1;
    }
};
















