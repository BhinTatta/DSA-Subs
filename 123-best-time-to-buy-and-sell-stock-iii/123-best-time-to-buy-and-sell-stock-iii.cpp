class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        vector<int> left(n) , right(n);
        left[0] = 0;
        right[n-1] = 0;
        
        int minleft = nums[0];
        for(int i = 1; i < n ; i++){
            minleft = min(minleft , nums[i]);
            left[i] = max(left[i-1]  , nums[i]-minleft);
        }
        
        int maxright = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            maxright = max(maxright , nums[i]);
            right[i] = max(right[i+1] , maxright - nums[i]);
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){            
            ans = max(ans , right[i]+left[i]);
        }
        return ans;
    }
};