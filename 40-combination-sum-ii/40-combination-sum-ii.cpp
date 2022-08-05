class Solution {
public:
    void solver(vector<vector<int>> &ans , vector<int> nums , vector<int> &arr , int sum , int idx , int target){
        
        if(sum==target){
            ans.push_back(arr);
            return;
        }
        if(sum > target || idx >nums.size()) return;
        
        for(int i = idx ; i < nums.size()  ; i++){
            
            if((i!=idx && nums[i]!= nums[i-1]) && sum+nums[i] <= target ){
                arr.push_back(nums[i]);
                solver(ans , nums , arr , sum+nums[i] , i+1 , target);
                arr.pop_back();
            }
            
            if(i==idx  && sum+nums[i] <= target){
                
                arr.push_back(nums[i]);
                solver(ans , nums , arr , sum+nums[i] , i+1 , target);
                arr.pop_back();
                
            }
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin() , candidates.end()); 
        vector<vector<int>> ans;
        vector<int> arr;
        int sum = 0;
        
        solver(ans , candidates , arr ,sum , 0 , target);
        
        return ans;
    }
};