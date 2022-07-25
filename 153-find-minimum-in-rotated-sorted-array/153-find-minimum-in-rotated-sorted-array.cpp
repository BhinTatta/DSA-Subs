class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        
        while(r-l>1){
            //cout<<l<<" "<<r<<endl;
            int mid = (l+r)/2;
            bool left = isokay(nums , l , mid);
            bool right = isokay(nums , mid , r);
            
            if(left && right) return nums[l];
            
            if(left) l = mid;
            else if(right) r = mid;
        }
        
        return min(nums[l],nums[r]);
    }
    
    bool isokay(vector<int>& nums , int l , int r){
        int mid = (l+r)/2;
        
        if( nums[l] <= nums[mid] && nums[mid]<= nums[r]) return true;
        return false;
    }
};