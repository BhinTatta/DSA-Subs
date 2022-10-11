class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        bool big[n];
        bool less[n];
        
        memset(big , 0 , sizeof(big));
        memset(less , 0 , sizeof(less));
        big[n-1] = false;
        less[0] = false;
        
        int maxi = nums[n-1];
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] < maxi){
                big[i] = true;
            }
            maxi = max(nums[i] , maxi);
        }
        
        int mini = nums[0];
        for(int i = 0 ; i < n ; i++){
            if(nums[i]>mini) less[i] = true;
            mini = min(mini , nums[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(big[i] && less[i]) return true;
        }
        
        return false;
    }
};