class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> dp(2001,0);
        for(int i : arr){
            dp[i+1000]++;
        }
        sort(begin(dp),end(dp));
        for(int i = 1 ; i < 2001 ; i++){
            if(dp[i] && dp[i]==dp[i-1]) return 0;
        }
        return 1;
    }
};