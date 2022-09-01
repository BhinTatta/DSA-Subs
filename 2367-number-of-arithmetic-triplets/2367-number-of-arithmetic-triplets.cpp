class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int curr = nums[i];
            if(mp.find(curr+diff)!=mp.end() && mp.find(curr+diff+diff)!=mp.end()) ans++;
        }
        return ans;
    }
};