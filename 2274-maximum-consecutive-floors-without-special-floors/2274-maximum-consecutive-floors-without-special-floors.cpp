class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = nums[0] - bottom;
        int prev = nums[0];
        for(int i = 1 ; i < n ; i++){
            int curr = nums[i];
            int diff = curr-prev-1;
            ans = max(ans,diff);
            prev = curr;
        }
        ans = max(ans , top-prev);
        return ans;
    }
};