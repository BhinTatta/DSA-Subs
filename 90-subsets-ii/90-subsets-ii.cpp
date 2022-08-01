class Solution {
public:
    
    void solver(vector<int> nums , vector<vector<int>> &ans , vector<int>arr , int i){ 
        if(i > nums.size()) return;
        ans.push_back(arr);
        int n = nums.size();      
        for(int j = i ; j < n ; j++){
            if(j != i && nums[j]!= nums[j-1]){
                arr.push_back(nums[j]);
                solver(nums,ans,arr,j+1);
                arr.pop_back();
            }
            if(j==i ){
                arr.push_back(nums[j]);
                solver(nums,ans,arr,j+1);
                arr.pop_back();
            }          
        }
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {        
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin() , nums.end());
        solver(nums , ans , arr , 0);       
        return ans;
    }
};