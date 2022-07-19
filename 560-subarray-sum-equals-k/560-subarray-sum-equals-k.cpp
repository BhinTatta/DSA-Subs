class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix;
        prefix.push_back(0);
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0;
        mp[0]=1;
        for(int i = 0 ; i < n ; i++){
            if(i < n)sum+=nums[i];
            prefix.push_back(sum);
            if(sum-k==0 && !mp[0]){
                mp[0]++;
                ans++;
            }
            else if(mp[sum-k]){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};