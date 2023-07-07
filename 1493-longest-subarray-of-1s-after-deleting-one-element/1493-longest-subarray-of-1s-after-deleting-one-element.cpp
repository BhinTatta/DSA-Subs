class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> temp;
        int i = 0 , n = nums.size();
        int ans = 0 , prev = 0;
        bool zero = false;
        while(i<n){
            if(nums[i]==0){
                if(zero){
                    prev = 0;
                }
                if(zero==false) zero = true;
                i++;
                continue;
            }
            zero = false;
            int len = 0;
            while(i<n && nums[i]==1){
                i++;
                len++;
            }
            ans = max(ans , prev+len);
            prev = len;
        }
        
        return ans==n ? n-1 : ans;
        
    }
};