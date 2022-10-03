class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int dp[n];
        int hash[n];
        for(int i = 0 ; i < n ; i++){
            dp[i] = 1;
            hash[i] = i;
        }
        
        int ans = 0, pos = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i]%nums[j] == 0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i]>ans){
                ans = dp[i];
                pos = i;
            }
        }
        
        vector<int>vec;
        for(int i = 0 ; i < ans ; i++){
            vec.push_back( nums[pos] );
            pos = hash[pos];
        }
        
        return vec;
    }
};