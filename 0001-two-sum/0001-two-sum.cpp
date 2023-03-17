class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int curr = nums[i] , req = target-curr;
            
            if(mp.find(req)!=mp.end()){
                return {i , mp[req]};
            }
            
            mp[curr] = i;
        }
        return ans;
    }
};