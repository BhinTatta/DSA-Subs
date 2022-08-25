class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0 , m = 0;
        int r = nums.size()-1;
        
        while(m<=r){
            if(nums[m]==2){
                swap(nums[r],nums[m]);
                r--;
            }
            else if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else{
                m++;
            }
        }
    }
};