class Solution {
public:
    bool helper(vector<int>nums , int m , int k , int mid){
        int boq = 0;
        int l = 0;
        while(l<nums.size()){
            
            int j = l;
            while(j<nums.size() && nums[j]<=mid) j++;
            boq += (j-l)/k;
            if(boq>=m) return 1;
            l = j+1;
        }
        
        return boq>=m;
    }
    
    int minDays(vector<int>& nums, int m, int k) {
        int r = *max_element(nums.begin() , nums.end());
        
        int l = 1;
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(helper(nums , m , k , mid)){
                ans = min(ans , mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};