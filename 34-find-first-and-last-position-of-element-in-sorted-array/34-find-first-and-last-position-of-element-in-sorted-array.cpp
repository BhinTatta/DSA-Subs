class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int lower = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        int upper = upper_bound(nums.begin() , nums.end() , target) - nums.begin();
        return (lower<nums.size() && nums[lower]==target) ?ans = {lower,upper-1} : ans = {-1,-1};
    }
};