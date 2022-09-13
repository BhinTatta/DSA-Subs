class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        int ans = 0;
        for(int i = 1 ; i < n ; i++ ){
            if(nums[i]>nums[i-1]){
                ans += nums[i]-nums[i-1];
            }
        }
        
        return ans;
    }
};