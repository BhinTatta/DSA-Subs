class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0;
        long long int n = nums.size() , i = 0;
        
        while(i<n){
            
            if(nums[i]){
                i++;
                continue;
            }
            
            long long int j = 0;
            
            while(i<n && !nums[i]){
                i++;
                j++;
            }
            
            ans += (j)*(j+1)/2;
        }
        
        return ans;
    }
};