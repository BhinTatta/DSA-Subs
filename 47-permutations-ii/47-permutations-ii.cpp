class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        solver(nums,ans,n,0);
        return ans;
    }
    
    void solver(vector<int> &nums , vector<vector<int>> &ans , int n, int i){
        if(i == n){
            ans.push_back(nums);
            return;
        } 
        unordered_map<int,int> mp;        
        for(int j = i ; j < n ; j++){
            if( mp.find(nums[j]) != mp.end() ) continue;
            mp[nums[j]]++;
            swap(nums[i],nums[j]);
            solver(nums,ans,n,i+1);
            swap(nums[i],nums[j]);
        }
    }
};