class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = maxsum(nums);
        int mini = minsum(nums);
        int total = accumulate(nums.begin() , nums.end() , 0);
        return max(maxi , total-mini);
    }
    
    int maxsum(vector<int>& nums) {
        int maxsum = nums[0];
        int cursum = 0;
        
        for (int i = 0 ; i < nums.size() ; i++){
            cursum += nums[i];
            
            if (cursum > maxsum){
                maxsum = cursum;
            }
            
            if (cursum < 0){
                cursum = 0;
            }
        }
        return maxsum;
        
    }
    
    int minsum(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int maxsum1 = nums[0];
        int cursum = 0;
        
        for (int i = 0 ; i < nums.size()-1 ; i++){
            cursum += nums[i];
            
            maxsum1 = min(maxsum1 , cursum);
            
            if (cursum > 0){
                cursum = 0;
            }
        }
        
        int maxsum2 = nums[1];
        cursum = 0;
        
        for (int i = 1 ; i < nums.size() ; i++){
            cursum += nums[i];
            
            maxsum2 = min(maxsum2 , cursum);
            
            if (cursum > 0){
                cursum = 0;
            }
        }
        return min(maxsum1 , maxsum2);
        
    }
};