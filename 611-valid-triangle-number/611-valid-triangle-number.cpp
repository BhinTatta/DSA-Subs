class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans = 0;
        for(int i = n-1 ; i > 0 ; i--){
            int a = nums[i];
            int r = i-1; 
            while(r > 0){
                int req = a - nums[r];
                int idx = upper_bound(nums.begin() , nums.end() , req) - nums.begin();
                if(idx<r) ans += r-idx;
                r--;
            }
        }
        
        return ans;
    }
};