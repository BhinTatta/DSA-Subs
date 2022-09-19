class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        
        if(n==1 || nums[0]<=nums[n-1]) return nums[0];
        
        while(r-l > 1){
            //cout<<l<<" "<<r<<endl;
            int mid = (l+r)/2;
            
            if(nums[mid-1] > nums[mid] ) return nums[mid];
            
            if(nums[mid] > nums[r]) l = mid+1;
            else r = mid-1;
        }
        
        return min(nums[l] , nums[r]);
    }
};