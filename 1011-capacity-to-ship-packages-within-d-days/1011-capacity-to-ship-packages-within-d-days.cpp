class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {      
        int l = 1 , r = INT_MAX-2 , ans;
        
        while(l<r){
            int curr = (l+r)/2;
            bool done = helper(nums , days , curr);
            if(done) r = curr;
            else l = curr+1;
            if(done) ans = min(ans , curr);
        }
        
        return ans;
    }
    
    bool helper(vector<int> &nums , int d , int w){
        int day = 0 , n = nums.size() , i = 0;
        
        while(i < n){
            if(nums[i] > w) return false;
            
            int curr = 0;     
            while(i<n && curr+nums[i] <= w ){
                curr += nums[i];
                i++;
            }
            
            day++;
        }
        
        return day <= d;        
    }
    
};