class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return n;
        int ans = 1;
        int l = 0 , r = 0;
        int comp = nums[0];
        while(r<n){
            int curr = nums[r];           
            while( l<r && (comp&curr) > 0){
                 comp ^= nums[l++];
            }
            comp |= curr;
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};