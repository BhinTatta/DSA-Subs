class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = INT_MAX;
        int sum = 0;
        int l = 0 , r = 0;
        for(r = 0 ; r < n ; r++){
            sum += nums[r];
            while(l<=r && sum >= target){
                minlen = min(minlen , r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return minlen==INT_MAX ? 0 : minlen;
    }
};