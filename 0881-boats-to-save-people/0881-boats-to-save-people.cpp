class Solution {
public:
    int numRescueBoats(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        int i = 0 , j = n-1 , ans = 0;
        
        while(i<=j){
            int curr = nums[j];
          
            if(i<j && curr+nums[i] <= k){
                curr += nums[i];
                i++;
            }
            j--;
            ans++;
        }
        
        return ans;
    }
};