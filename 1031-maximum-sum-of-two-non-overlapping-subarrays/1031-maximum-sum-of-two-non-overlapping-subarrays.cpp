class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int one, int two) {
        int n = nums.size() , sum = 0;
        for(int i = 0 ; i < n ; i++){
            nums[i] += sum;
            sum = nums[i];
        }
        nums.insert(nums.begin() , 0);
        int ans = helper(nums , one , two , 1);
        return ans;
    }
    
    int helper(vector<int>&nums , int one , int two , int i){
        if(i>=nums.size()) return 0;
        int n = nums.size();
        int dont = helper(nums , one , two , i+1);
        int maxi = 0;
        
        for(int j = two ; j < i ; j++){
            maxi = max(maxi , nums[j] - nums[j-two] );
        }
        for(int j = i+one+two-1 ; j < n ; j++){
            maxi = max(maxi , nums[j] - nums[j-two] );
        }
        int sum = 0;
        if(i+one<=n) sum = nums[i+one-1] - nums[i-1];
        return max(maxi+sum , dont);
    }
};