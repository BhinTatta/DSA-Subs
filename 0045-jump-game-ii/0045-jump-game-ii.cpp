class Solution {
public:
    
    int n;
    unordered_map<int,int> mp;
    int jump(vector<int>& nums) {
        int ans = INT_MAX;
        n = nums.size();
        
        int x = helper(nums , 0);
        return x;
    }
    
    int helper(vector<int> &nums , int i){
        if(i >= n) return 1e6;
        if(i == n-1) return 0;
        if(nums[i]==0) return 1e6;
        
        if(mp.find(i)!=mp.end()) return mp[i];
        
        int mini = INT_MAX;
        
        for(int j = 1 ; j <= nums[i] ; j++){
            mini =  min(mini , 1 +  helper(nums , i+j));
        }
        
        return mp[i] = mini;
    }
};