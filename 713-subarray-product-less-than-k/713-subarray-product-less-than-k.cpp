class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        long long prod = 1;
        int l = 0 , r = 0;
        
        while(r<n){
            prod *= nums[r];
            
            
            while(prod>=k && l <= r){
                prod /= nums[l];
                l++;
            }
            
            ans += r-l+1;
            
            r++;
        }
        
        return ans;
        
    }
};