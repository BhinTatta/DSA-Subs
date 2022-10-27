class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;
        int pre = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int j = 0 ; j < n ; j++){
            int i = nums[j];
            pre += i;
            if(k!=0) pre = pre%k;
            int mod = pre;
            if(mp.find(mod)!=mp.end()){
                if(j - mp[mod] > 1) return true;
            }
            else mp[mod] = j;
        }
        return false;
    }
};