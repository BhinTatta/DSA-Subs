class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int ans = 0;
        vector<int>dp(n,0);
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = nums[i];
            int len = 0;
            for(auto it : mp){
                if(it.first > curr){
                    len = max(it.second , len);
                }
            }
            mp[curr] = 1 + len;
            ans = max(ans,len+1);
        }
        return ans;
    }
};