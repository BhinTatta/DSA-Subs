class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        
        for(int i = 0 ; i < n ; i++ ){
            int curr = nums[i];
            int pos = lower_bound(dp.begin() , dp.end() , curr) - dp.begin();
            if (pos >= dp.size()){
                dp.push_back(curr);
            }
            else{
                dp[pos] = curr;
            }
            if(dp.size()>2) return true;
        }
        
        
        return dp.size() > 2;
    }
};