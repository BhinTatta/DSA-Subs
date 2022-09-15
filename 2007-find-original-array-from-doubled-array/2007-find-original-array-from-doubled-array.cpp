class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2==1) return {};
        
        sort(nums.begin() , nums.end());
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++) mp[nums[i]]++;
        
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            int x = nums[i];
            
            if(mp.find(2*x)!=mp.end() && mp[x]!=0 && mp[x*2]!=0){
                mp[x]--;
                mp[2*x]--;
                ans.push_back(x);
            }
        }
        
        for(auto it : mp) if(it.second!=0) return {};
        
        return ans;
    }
};