class Solution {
public:
    int n;
    void solver(vector<vector<int>> &ans , vector<int> nums, vector<int>arr , int sum , int idx , int target){
        if(sum==target){
            ans.push_back(arr);
            return;
        }
        if(sum>target || idx > n) return;
        
        for(int i = idx ; i < nums.size() ; i++){
            if(nums[i]+sum <= target){
                arr.push_back(nums[i]);
                solver(ans,nums,arr,sum+nums[i] , i , target);
                arr.pop_back();
            }
        }       
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> ans;
        vector<int> arr;
        int sum = 0;
        
        solver(ans , candidates , arr , sum , 0 , target);
        
        return ans;
        
    }
};