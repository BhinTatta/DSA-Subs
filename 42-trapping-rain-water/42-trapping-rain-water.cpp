class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        vector<int> left(n);
        for(int i = 0 ; i < n ; i ++){
            maxi = max(maxi , nums[i]);
            left[i] = maxi;
        }
        maxi = nums[n-1];
        vector<int> right(n);
        for(int i = n-1 ; i >= 0 ; i--){
            maxi = max(maxi , nums[i]);
            right[i] = maxi;
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int water =  min(left[i] , right[i]) - nums[i];
            if(water>0) ans += water;
        }
        
        return ans;
    }
};