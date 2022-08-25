class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = nums.size();
        
        while(l<r){
            int mid = (l+r)/2;
            int curr = nums[mid];
            if(curr == target) return mid;
            if(curr < target) l = mid+1;
            if(curr > target) r = mid-1;
        }
        if(l<n && nums[l] < target) return l+1;
        return l;
    }
};