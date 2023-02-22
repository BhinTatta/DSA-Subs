class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        //sort(nums.begin() , nums.end());
        int n = nums.size();
        int l = 1 , r = INT_MAX-2 , ans;
        
        while(l<r){
            int curr = (l+r)/2;
            //cout<<l<<" "<<r<<" = "<<curr<<endl;
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
            int curr = 0;     
            if(nums[i] > w) return false;
            while(i<n && curr+nums[i] <= w ){
                curr += nums[i];
                i++;
            }
            
            day++;
        }
        // cout<<endl;
        return day <= d;
        
    }
    
};