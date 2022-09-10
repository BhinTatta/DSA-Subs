class Solution {
private:
    unordered_map<int,vector<int>> mp;
public:    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> ans;        
        for(int i = 0 ; i < nums.size() ; i++){
            auto it = helper(nums,i);
            if(it.size()>ans.size()) ans = it;
        }      
        return ans;
    }
    
    vector<int> helper(vector<int>&nums , int i){
        if(i>=nums.size()) return {};
        if(mp.count(i)) return mp[i];     
        vector<int> curr;
        
        for(int j = i+1 ; j < nums.size() ; j++){
            if(nums[j]%nums[i]!=0) continue;
            
            vector<int> temp = helper(nums,j);
            if(temp.size() > curr.size()) curr = temp;
        }
        mp[i] = curr;
        mp[i].push_back(nums[i]);
        return mp[i];
    }
};