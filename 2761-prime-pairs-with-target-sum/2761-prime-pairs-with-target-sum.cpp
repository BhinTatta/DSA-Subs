class Solution {
private:
    unordered_map<int,int> mp;
public:
    
    void prime(int n){
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 2 ; i*i < n ; i++){
            int j = 2;
            if(dp[i]) continue;
            while(i*j < n){
                dp[i*j]=1;
                j++;
            }
        }
        for(int i = 2 ; i <= n ; i++){
            if(!dp[i]){
                //cout<<i<<" "; 
                mp[i]++;
            }
            
        }
    }
    
    vector<vector<int>> findPrimePairs(int n) {
        prime(n);
        vector<vector<int>> ans;
        for(int i = 2 ; i <= n/2 ; i++){
            int req = n-i;
            if(mp.find(i)!=mp.end() && mp.find(req)!=mp.end()){
                ans.push_back({i,req});
            }
        }
        return ans;
    }
};