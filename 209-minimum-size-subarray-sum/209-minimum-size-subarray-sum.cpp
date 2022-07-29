class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = INT_MAX;
        int sum = 0;
        int l = 0 , r = 0;
        while(r < n){
            sum += nums[r];

            while(l<=r && sum >= target){
                minlen = min(minlen , r-l+1);
                sum -= nums[l];
                l++;
            }
            
            r++;

        }
        return minlen==INT_MAX ? 0 : minlen;
    }
};