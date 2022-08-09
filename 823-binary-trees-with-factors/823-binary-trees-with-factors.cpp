class Solution {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> data;
    int n;
    int mod = pow(10,9)+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]] = i;
        }
        
        vector<long> dp(n+1,-1);
        return solver(arr,0,dp);
    }
    
    int solver(vector<int>&arr , int i, vector<long>&dp){
        if(i>=n) return 0;
        int ans = 1;
        int curr = arr[i];
        int j = 0;
        while(j<n && arr[j]<=curr/2){
            int req = curr/arr[j];
            if(curr%arr[j]!=0){
                j++;
                continue;
            }
            else{
                if(mp.find(req)!=mp.end()){
                    long long temp = (dp[j] * dp[mp[req]])%mod;
                    ans = (ans+temp)%mod;
                }
            }
            j++;
        }
        dp[i]=ans%mod;
        //cout<<arr[i]<<" = "<<ans<<endl;
        return (ans + solver(arr,i+1,dp))%mod;
    }
};