class Solution {
public:
    bool helper(vector<int>&nums , int k , int pen){
        int op = 0;
        for(int x : nums){
            if(x<=pen) continue;
            op += x/pen;
            if(x%pen==0) op--;
        }
        return op <= k;
    }
    int minimumSize(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin() , nums.end());
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(helper(nums,k ,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};