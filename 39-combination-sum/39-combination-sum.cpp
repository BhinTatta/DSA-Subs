class Solution {
public:
    int n ;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        n = nums.size();
        int k = target;
        
        vector<vector<int>> ans;
        vector<int>temp;
        helper(nums , ans , temp , k , 0);
        return ans;
    }
    
    void helper(vector<int> &nums , vector<vector<int>> &ans, vector<int>temp , int sum , int i){
        if( i >= n || sum < 0){
            if(sum==0) ans.push_back(temp);
            return;
        }
        
        //take
        if(nums[i] > sum) helper(nums , ans , temp , sum , i+1);
        else{
            helper(nums , ans , temp , sum , i+1);
            temp.push_back(nums[i]);
            helper(nums , ans , temp , sum - nums[i] , i);
            temp.pop_back();
        }
        return;
    }
};